#include "Int16.hpp"

Int16::Int16(){
	my_val = 0;
	_my_type = e_Int16;
	_my_pre = 1;
	return ;
}

Int16::Int16(std::string const& val){
	my_val = stoi(val);
	// std::cout << "val = " << val << std::endl;
	// std::cout << "my_val = " << my_val << std::endl;
	_my_type = e_Int16;
	_my_pre = 1;
	return ;
}

eOperandType	Int16::getType() const{
	return (e_Int16);
}

int 			Int16::getPrecision() const{
	return (_my_pre);
}

IOperand const*	Int16::operator+(IOperand const & rhs) const{
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

IOperand const*	Int16::operator-(IOperand const & rhs) const{
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

IOperand const*	Int16::operator*(IOperand const & rhs) const{
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

IOperand const*	Int16::operator/(IOperand const & rhs) const{
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

IOperand const*	Int16::operator%(IOperand const & rhs) const{
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

std::string const & Int16::toString() const{
	std::string *str = new std::string(std::to_string(my_val));
	return (*str);
}

Int16::~Int16(){
	return ;
}