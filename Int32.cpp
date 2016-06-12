#include "Int32.hpp"
# include <climits>
# include <cstdint>

Int32::Int32(){
	my_val = 0;
	_my_type = e_Int32;
	_my_pre = 2;
	return ;
}

Int32::Int32(std::string const& val){
	my_val = stoi(val);
	// std::cout << "val = " << val << std::endl;
	// std::cout << "my_val = " << my_val << std::endl;
	_my_type = e_Int32;
	_my_pre = 2;
	return ;
}

eOperandType	Int32::getType() const{
	return (e_Int32);
}

int 			Int32::getPrecision() const{
	return (_my_pre);
}

IOperand const*	Int32::operator+(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();
	newvalue = my_val + stod(rhs.toString());
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

IOperand const*	Int32::operator-(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();
	newvalue = my_val - stod(rhs.toString());
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

IOperand const*	Int32::operator*(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();
	newvalue = my_val * stod(rhs.toString());
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

IOperand const*	Int32::operator/(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();
	newvalue = my_val / stod(rhs.toString());
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

IOperand const*	Int32::operator%(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();
	newvalue = std::fmod(my_val, stod(rhs.toString()));
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

std::string const & Int32::toString() const{
	std::string *str = new std::string(std::to_string(my_val));
	return (*str);
}

Int32::~Int32(){
	return ;
}