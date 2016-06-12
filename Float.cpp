#include "Float.hpp"
#include <sstream>

Float::Float(){
	my_val = 0;
	_my_type = e_Float;
	_my_pre = 4;
	return ;
}

Float::Float(std::string const& val){
	my_val = stod(val);
	// std::cout << "val = " << val << std::endl;
	// std::cout << "my_val = " << my_val << std::endl;
	_my_type = e_Float;
	_my_pre = 4;
	return ;
}

eOperandType	Float::getType() const{
	return (e_Float);
}

int 			Float::getPrecision() const{
	return (_my_pre);
}

IOperand const*	Float::operator+(IOperand const & rhs) const{
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

IOperand const*	Float::operator-(IOperand const & rhs) const{
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

IOperand const*	Float::operator*(IOperand const & rhs) const{
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

IOperand const*	Float::operator/(IOperand const & rhs) const{
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

IOperand const*	Float::operator%(IOperand const & rhs) const{
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

std::string const & Float::toString() const{
	std::string *str = new std::string(std::to_string(my_val));
	std::ostringstream os; 

	os << my_val;
	*str = os.str();
	return (*str);
}

Float::~Float(){
	return ;
}