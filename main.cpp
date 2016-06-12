#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <vector>

#include "VM.hpp"

void				ft_recover_value(size_t pos, std::string inst, std::string line){
	std::cout << inst << std::endl;
	line.replace(pos, inst.length(), "");
	std::cout << "line = " << line << std::endl;
}

std::string			ft_integer(std::string line){
	bool 			neg = false;
	std::string 	tmp;

	if (line.compare(0, 1, "(") != 0 || line.compare(line.length() - 1, 1, ")") != 0){
		std::cout << "line = <" << line << ">" << std::endl;
		throw std::runtime_error("\033[1;31merror:\033[0m number must be surround by () '" + line + '\'');
	}
	else{
		line = line.substr(1);
		line = line.substr(0, line.length()-1);
	}
	if (line.compare(0, 1, "-") == 0)
	{
		tmp = "-";
		neg = true;
		line = line.substr(1);
	}
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
	{
		if ((isdigit(*it) == false) && (it+1) != line.end())
			throw std::runtime_error("\033[1;31merror:\033[0m use of non INTEGER '" + line + '\'');
		tmp += *it;
	}
	return (tmp);
}

std::string			ft_not_integer(std::string line){
	bool 			neg = false;
	std::string 	tmp;

	if (line.compare(0, 1, "(") != 0 || line.compare(line.length() - 1, 1, ")") != 0)
		throw std::runtime_error("\033[1;31merror:\033[0m number must be surround by () , ')' expected at end of '" + line + '\'');
	else{
		line = line.substr(1);
		line = line.substr(0, line.length()-1);
	}
	if (line.compare(0, 1, "-") == 0)
	{
		tmp = "-";
		neg = true;
		line = line.substr(1);
	}
	if (std::count(line.begin(), line.end(), '.') > 1 || std::count(line.begin(), line.end(), 'e') > 1 )
		throw std::runtime_error("\033[1;31merror:\033[0m not a number '" + line + '\'');
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
	{
		if (*it == '.' && (it == line.begin() || it == (line.end() - 1)))
			throw std::runtime_error("\033[1;31merror:\033[0m 1not a number '" + line + '\'');
		else if ((isdigit(*it) == false) && (*it != 'e' && *it != '-' && *it != '+' && *it != '.'))
		{
			std::cout << "*it = " << *it << std::endl;
				std::cout << "error 1" << std:: endl;
			throw std::runtime_error("\033[1;31merror:\033[0m 2not a number '" + line + '\'');
		}
		tmp += *it;
	}
	return (tmp);
}

std::string				ft_val(std::string line, std::string cmd){
	std::string tmp;
	size_t 		str_begin;
	// std::cout << "VAL = <" << line << ">" << std::endl;

	if (line[0] == ' ' || line[0] == '\t')
		line = line.substr(1);
	str_begin = line.find_first_of(" \t");
	if (str_begin != std::string::npos)
		line = line.substr(0, str_begin);
	if ((line.compare(0, 4, "int8") == 0)){
		tmp = line.substr(4);
		tmp = "int8 " + ft_integer(tmp);
	}
	else if ((line.compare(0, 5, "int16") == 0)){
		tmp = line.substr(5);
		tmp = "int16 " + ft_integer(tmp);
	}
	else if ((line.compare(0, 5, "int32") == 0)){
		tmp = line.substr(5);
		tmp = "int32 " + ft_integer(tmp);
	}
	else if ((line.compare(0, 5, "float") == 0)){
		tmp = line.substr(5);
		tmp = "float " + ft_not_integer(tmp);
	}
	else if ((line.compare(0, 6, "double") == 0)){
		tmp = line.substr(6);
		tmp = "double " + ft_not_integer(tmp);
	}
	else{
		line = line.substr(0, line.find_first_of("( "));
		if (!line.empty())
			throw std::runtime_error("\033[1;31merror:\033[0m use of undeclared VALUE '" + line + '\'');
		else
			throw std::runtime_error("\033[1;31merror:\033[0m missing VALUE for " + cmd);			
	}
	return (tmp);
}

std::string				ft_inst(std::string line){
	std::string 		tmp;
	std::string 		ret;

	if ((line.compare(0, 4, "push") == 0)){
		tmp = line.substr(4);
		tmp = ft_val(tmp, "PUSH");
		return (ret = "push " + tmp);
	}
	else if ((line.compare(0, 6, "assert") == 0)){
		tmp = line.substr(6);
		tmp = ft_val(tmp, "ASSERT");
		return (ret = "assert " + tmp);
	}
	else if ((line.compare(0, 3, "pop") == 0)){
		tmp = line.substr(3);
		ret = "pop";
	}
	else if ((line.compare(0, 4, "dump") == 0)){
		tmp = line.substr(4);
		ret = "dump";
	}
	else if ((line.compare(0, 3, "add") == 0)){
		tmp = line.substr(3);
		ret = "add";
	}
	else if ((line.compare(0, 3, "sub") == 0)){
		tmp = line.substr(3);
		ret = "sub";
	}
	else if ((line.compare(0, 3, "mul") == 0)){
		tmp = line.substr(3);
		ret = "mul";
	}
	else if ((line.compare(0, 3, "div") == 0)){
		tmp = line.substr(3);
		ret = "div";
	}
	else if ((line.compare(0, 3, "mod") == 0)){
		tmp = line.substr(3);
		ret = "mod";
	}
	else if ((line.compare(0, 5, "print") == 0)){
		tmp = line.substr(5);
		ret = "print";
	}
	else if ((line.compare(0, 4, "exit") == 0)){
		tmp = line.substr(4);
		ret = "exit";
	}
	else{
		line = line.substr(0, line.find_first_of(" \t"));
		throw std::runtime_error("\033[1;31merror:\033[0m use of undeclared INSTR '" + line + '\'');
	}
	if (tmp.length() != 0){
		// std::cout << "tmp = <" << tmp << ">" << std::endl
		if (tmp.find_first_not_of(" \t") != std::string::npos)
			throw std::runtime_error("\033[1;31merror:\033[0m unexpected INSTR '" + tmp + '\'' + " at end of '" + line + '\'');
	}
	return ret;
}

std::string			ft_lexer(std::string line){
	size_t str_begin = line.find_first_not_of(" \t");
	if (str_begin != std::string::npos)
		line = line.substr(str_begin);
	size_t str_end = line.find(";");
	if (str_end != std::string::npos)
		line = line.substr(0, str_end);
	if (line[line.length() - 1] == ' ' || line[line.length() - 1] == '\t' ){
		str_end = line.find_last_of(" \t");
		if (str_end != std::string::npos)
			line = line.substr(0, str_end);
	}
	return (line);
}


void				ft_run(std::vector<std::string> tab){
	VM		my_vm = VM();
	for (auto &inst : tab)
		my_vm.Execute(inst);
}

void				ft_read_standard_input(){
	std::vector<std::string> 	tab_str;
	std::string 	line;
	int 			i = 0;

	std::cout << "<<<READ INPUT MODE>>>" << std::endl;
	while (42)
	{
		std::getline(std::cin, line);
		size_t found = line.find(";;");
		if (found != std::string::npos)
			break ;
		try{
			i++;
			line = ft_lexer(line);
			if (!line.empty())
				tab_str.push_back(ft_inst(line));
		}
		catch(std::exception &e){
			std::cout << "\n\033[1;31mSyntax Error :\033[0m stdin line " << i << ": " << e.what() << "\n\t\033[1;31m->\033[0m " << line << std::endl;
		}
	}
	std::cout << "====================================" << std::endl;
	ft_run(tab_str);
}

void				ft_read_from_file(std::string filename){
	std::ifstream	file;
	std::string 	line;
	std::vector<std::string> 	tab_str;
	bool 			is_exit = false;
	int 			i = 0;

	std::cout << "<<<READ FILE MODE>>>" << std::endl;
	std::ifstream ifs (filename.c_str(), std::ifstream::in);
	if (!ifs.is_open()){
		ifs.close();
		throw std::runtime_error("Usage Error : Unable to open " + filename);
	}
	while (getline(ifs, line))
	{
		try{
			i++;
			line = ft_lexer(line);
			if (!line.empty())
				tab_str.push_back(ft_inst(line));
		}
		catch(std::exception &e){
			std::cout << "\n\033[1;31mSyntax Error :\033[0m " << filename << " line " << i << ": " << e.what() << "\n\t\033[1;31m->\033[0m " << line << std::endl;
		}
	}
	if (i == 0)
		std::cout << "Warning : it seem that you trying to pass a folder instead of a file / or a empty file" << std::endl;
	for (std::vector<std::string>::iterator it = tab_str.begin(); it != tab_str.end(); ++it){
		if (it->compare(0, 4, "exit") == 0)
			is_exit = true;
		std::cout << *it << std::endl;
	}
	std::cout << "====================================" << std::endl;
	if (is_exit == false && tab_str.size() > 0)
		throw std::runtime_error("Syntax\033[1;31m Error:\033[0m Missing exit instruction after '" + tab_str.back() + '\'');
	else if (is_exit == false && tab_str.size() == 0)
		throw std::runtime_error("Syntax\033[1;31m Error:\033[0m Missing exit instruction on the empty file '\'");
	ft_run(tab_str);

	ifs.close();	
}

int 				main(int ac, char const *av[])
{
	if (ac == 1){
		try {
			ft_read_standard_input();
		}
		catch (std::exception &e){
			std::cout << "\033[1;31mCatched\033[0m : "  << e.what() << std::endl;
		}
	}
	else{
		try {
			ft_read_from_file(av[1]);
		}
		catch (std::exception &e){
			std::cout << "\033[1;31mCatched\033[0m : "  << e.what() << std::endl;
		}
	}
	return 0;
}