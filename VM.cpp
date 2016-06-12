# include "VM.hpp"
#include <vector>

VM::VM() : _Stack(new MutantStack<const IOperand*>()){

}

void			VM::Execute(std::string inst){
	try{
		if (inst.compare(0, 6, "assert") == 0)
			assert(inst.substr(7));
		if (inst.compare(0, 4, "push") == 0)
			push(inst.substr(5));
		if (inst == "add")
			add();
		if (inst == "pop")
			pop();
		if (inst == "dump")
			dump();
		if (inst == "sub")
			sub();
		if (inst == "mul")
			mul();
		if (inst == "div")
			div();
		if (inst == "mod")
			mod();
		if (inst == "print")
			print();
		if (inst == "exit")
			exit();
	}
	catch (VMException&e){
		std::cout << "\033[1;31mCatched\033[0m : " << e.what() << std::endl;
	}
	catch (std::out_of_range &e){
		std::cout << "\033[1;31mCatched\033[0m : " << e.what() << std::endl;
	}
}

eOperandType	VM::getType(std::string inst) const{
	size_t 		i = inst.find(" ");

	if (i != std::string::npos)
		inst = inst.substr(0, i);
	if (inst == "Int8" || inst == "int8")
		return (e_Int8);
	if (inst == "Int16" || inst == "int16")
		return (e_Int16);
	if (inst == "Int32" || inst == "int32")
		return (e_Int32);
	if (inst == "Float" || inst == "float")
		return (e_Float);
	if (inst == "Double" || inst == "double")
		return (e_Double);
	return (e_Double);
}


std::string		VM::getValue(std::string inst) const{
	size_t 			i = inst.find(" ");
	return (inst.substr(i+1));
}

void			VM::push(std::string inst) const{
	Factory			f;
	try{
		_Stack->push(f.createOperand(getType(inst), getValue(inst)));
	}
	catch (std::out_of_range &e){
		std::cout << "\033[1;31mCatched\033[0m : " << e.what() <<  " for Value : '" << getValue(inst) << "'" << std::endl;
	}	
}

void			VM::assert(std::string inst){
	if (_Stack->size() < 1)
		throw VMException ("'assert' : Stack is empty");
	if (_Stack->top()->getType() != getType(inst))
		throw VMException ("'assert' : type is not same");
	std::string tmp1 = _Stack->top()->toString();
	std::string tmp2 = getValue(inst);
	if (tmp1 != tmp2)
	{
		throw VMException ("'ASSERT' : Value are not the same");
	}
}

void			VM::pop(){
	if (_Stack->size() < 1)
		throw VMException ("'POP' : Unable to Pop on a empty stack");
	else
		_Stack->pop();
}

void			VM::dump(){
	MutantStack<const IOperand *>::iterator my_Iterator;
	std::vector<std::string> tab;


	for (my_Iterator = _Stack->begin(); my_Iterator < _Stack->end(); my_Iterator++)
		tab.insert (tab.begin(), (*my_Iterator)->toString());
	for (std::vector<std::string>::iterator it = tab.begin(); it != tab.end(); ++it)
		std::cout << *it << std::endl;
}

void			VM::add(){
	const IOperand *tmp1;
	const IOperand *tmp2;
	if (_Stack->size() < 2)
		throw VMException ("'ADD' : Stack is to small, " + std::to_string(_Stack->size()) + " element");
	tmp1 = _Stack->top();
	_Stack->pop();
	tmp2 = _Stack->top();
	_Stack->pop();
	try{
		_Stack->push(*tmp1 + *tmp2);
	}
	catch (std::out_of_range &e){
		throw std::runtime_error("ABRACADABRA out_of_range add"); 
		std::cout << "\033[1;31mCatched\033[0m : " << e.what() << std::endl;
	}	
}

void			VM::sub(){
	const IOperand *tmp1;
	const IOperand *tmp2;
	if (_Stack->size() < 2)
		throw VMException ("'SUB' : Stack is to small, " + std::to_string(_Stack->size()) + " element");
	tmp1 = _Stack->top();
	_Stack->pop();
	tmp2 = _Stack->top();
	_Stack->pop();
	try{
		_Stack->push(*tmp1 - *tmp2);
	}
	catch (std::out_of_range &e){
		throw std::runtime_error("ABRACADABRA out_of_range sub"); 
		std::cout << "\033[1;31mCatched\033[0m : " << e.what() << std::endl;
	}	
}

void			VM::mul(){
	const IOperand *tmp1;
	const IOperand *tmp2;
	if (_Stack->size() < 2)
		throw VMException ("'MUL' : Stack is to small, " + std::to_string(_Stack->size()) + " element");
	tmp1 = _Stack->top();
	_Stack->pop();
	tmp2 = _Stack->top();
	_Stack->pop();
	try{
		_Stack->push(*tmp1 * *tmp2);
	}
	catch (std::out_of_range &e){
		throw std::runtime_error("ABRACADABRA out_of_range mul"); 
		std::cout << "\033[1;31mCatched\033[0m : " << e.what() << std::endl;
	}	
}

void			VM::div(){
	const IOperand *tmp1;
	const IOperand *tmp2;
	if (_Stack->size() < 2)
		throw VMException ("'DIV' : Stack is to small, " + std::to_string(_Stack->size()) + " element");
	tmp1 = _Stack->top();
	_Stack->pop();
	tmp2 = _Stack->top();
	_Stack->pop();
	if (tmp1->toString().compare("0") == 0)
		throw VMException ("'DIV' :  Impossible division of " + tmp2->toString() + " by '0', floating point");
	if (tmp2->toString().compare("0") == 0)
		throw VMException ("'DIV' :  Impossible division of " + tmp1->toString() + " by '0', floating point");	
	try{
		_Stack->push(*tmp1 / *tmp2);
	}
	catch (std::out_of_range &e){
		throw std::runtime_error ("ABRACADABRA out_of_range div");
		std::cout << "\033[1;31mCatched\033[0m : " << e.what() << std::endl;
	}	
}

void			VM::mod(){
	const IOperand *tmp1;
	const IOperand *tmp2;
	if (_Stack->size() < 2)
		throw VMException ("MOD : Stack is to small, " + std::to_string(_Stack->size()) + " element");
	tmp1 = _Stack->top();
	_Stack->pop();
	tmp2 = _Stack->top();
	_Stack->pop();
	if (tmp1->toString().compare("0") == 0)
		throw VMException ("'MOD' :  Impossible modulo of " + tmp2->toString() + " by '0', floating point");
	if (tmp2->toString().compare("0") == 0)
		throw VMException ("'MOD' :  Impossible modulo of " + tmp1->toString() + " by '0', floating point");	
	try{
		_Stack->push(*tmp1 % *tmp2);
	}
	catch (std::out_of_range &e){
		throw std::runtime_error ("ABRACADABRA out_of_range mod");
		std::cout << "\033[1;31mCatched\033[0m : " << e.what() << std::endl;
	}	
}

void			VM::print(){
	if (_Stack->top()->getType() == e_Int8)
		std::cout << static_cast<char>(stoi((_Stack->top()->toString()))) << std::endl;
}

void			VM::exit(){

}

VM::~VM(){

}

// VMException

VM::VMException::VMException(std::string str) throw() : std::runtime_error(str){
	return ;
}

VM::VMException::~VMException() throw() {
	return ;	
}

const char* 	VM::VMException::VMException::what() const throw() {
	std::string ret = "VM Error : " + std::string(std::runtime_error::what());
	return ret.c_str();
}