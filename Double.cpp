#include "Double.hpp"
#include <sstream>

Double::Double(){
	my_val = 0;
	_my_type = e_Double;
	_my_pre = 5;
	return ;
}

Double::Double(std::string const& val){
	my_val = stod(val);
	// std::cout << "val = " << val << std::endl;
	// std::cout << "my_val = " << my_val << std::endl;
	_my_type = e_Double;
	_my_pre = 5;
	return ;
}

eOperandType	Double::getType() const{
	return (e_Double);
}

int 			Double::getPrecision() const{
	return (_my_pre);
}

IOperand const*	Double::operator+(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();	newvalue = my_val + stod(rhs.toString());
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

IOperand const*	Double::operator-(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();	newvalue = my_val - stod(rhs.toString());
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

IOperand const*	Double::operator*(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();	newvalue = my_val * stod(rhs.toString());
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

IOperand const*	Double::operator/(IOperand const & rhs) const{
	double 			newvalue;
	Factory 		f;
	eOperandType 	newtype;
	if (getPrecision() > rhs.getPrecision())
		newtype = getType();
	else
		newtype = rhs.getType();	newvalue = my_val / stod(rhs.toString());
	return (f.createOperand(newtype, std::to_string(newvalue)));
}

IOperand const*	Double::operator%(IOperand const & rhs) const{
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

std::string const & Double::toString() const{
	std::string *str = new std::string(std::to_string(my_val));
	std::ostringstream os; 

	os << my_val;
	*str = os.str();
	return (*str);
}

Double::~Double(){
	return ;
}