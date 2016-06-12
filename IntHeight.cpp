#include "IntHeight.hpp"
#include <sstream>

IntHeight::IntHeight(){
	my_val = 0;
	_my_type = e_Int8;
	_my_pre = 0;
	return ;
}

IntHeight::IntHeight(std::string const& val){
	my_val = stoi(val);
	// std::cout << "val = " << val << std::endl;
	// std::cout << "my_val = " << my_val << std::endl;
	_my_type = e_Int8;
	_my_pre = 0;
	return ;
}

eOperandType	IntHeight::getType() const{
	return (e_Int8);
}

int 			IntHeight::getPrecision() const{
	return (_my_pre);
}

IOperand const*	IntHeight::operator+(IOperand const & rhs) const{
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

IOperand const*	IntHeight::operator-(IOperand const & rhs) const{
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

IOperand const*	IntHeight::operator*(IOperand const & rhs) const{
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

IOperand const*	IntHeight::operator/(IOperand const & rhs) const{
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

IOperand const*	IntHeight::operator%(IOperand const & rhs) const{
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

std::string const & IntHeight::toString() const{
	std::string *str = new std::string(std::to_string(my_val));
	return (*str);
}

IntHeight::~IntHeight(){
	return ;
}