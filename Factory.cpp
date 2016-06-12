#include "Factory.hpp"
# include "IntHeight.hpp"
# include "Int16.hpp"
# include "Int32.hpp"
# include "Double.hpp"
# include "Float.hpp"
# include <climits>
# include <cstdint>
# include <cfloat>
 #include <sstream>

Factory::Factory() {}

Factory::~Factory() {}

IOperand const * Factory::createOperand (eOperandType type, std::string const & value) const{
	
	int 	i = 0;
	if (type == e_Int8)
		i = 0;
	if (type == e_Int16)
		i = 1;
	if (type == e_Int32)
		i = 2;
	if (type == e_Float)
		i = 3;
	if (type == e_Double)
		i = 4;
	IOperand const *	(Factory::*ptr[5])(std::string const &) const={
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	return (this->*ptr[i])(value);
}

IOperand const * Factory::createInt8 (std::string const& value) const{
	try{
		double tmp;
		std::stringstream 	my_str;

		tmp = stod(value);
		if (tmp < std::numeric_limits<std::int8_t>::min()){
			my_str << std::fixed << std::setprecision(0) << tmp;
			throw UnderException("'" + std::to_string(stoi(value)) + "'" + " is too small for Int8, min is " + std::to_string(std::numeric_limits<std::int8_t>::min()));
		}
		else if (tmp > std::numeric_limits<std::int8_t>::max()){
			my_str << std::fixed << std::setprecision(0) << tmp;
			throw OverException("'" + std::to_string(stoi(value)) + "'" + " is too big for Int8, max is " + std::to_string(std::numeric_limits<std::int8_t>::max()));
		}
	}
	catch (std::out_of_range &e){
		throw e;
	}
	IntHeight 		*obj = new IntHeight(value);
	return (obj);
}

IOperand const * Factory::createInt16 (std::string const& value) const{
	try{
		double tmp;
		std::stringstream 	my_str;

		tmp = stod(value);
		if (tmp < std::numeric_limits<std::int16_t>::lowest()){
			my_str << std::fixed << std::setprecision(0) << tmp;
			throw UnderException("'" + std::to_string(stoi(value)) + "'" + " is too small for Int16, min is " + std::to_string(std::numeric_limits<std::int16_t>::min()));
		}
		else if (tmp > std::numeric_limits<std::int16_t>::max()){
			my_str << std::fixed << std::setprecision(0) << tmp;
			throw OverException("'" + std::to_string(stoi(value)) + "'" + " is too big for Int16, max is " + std::to_string(std::numeric_limits<std::int16_t>::max()));
		}
	}
	catch (std::out_of_range &e){
		throw e;
	}
	Int16 		*obj = new Int16(value);
	return (obj);
}

IOperand const * Factory::createInt32 (std::string const& value) const{
	try{
		double tmp;
		std::stringstream 	my_str;

		tmp = stod(value);
		if (tmp < std::numeric_limits<std::int32_t>::lowest()){
			my_str << std::fixed << std::setprecision(0) << tmp;
			throw UnderException("'" + my_str.str() + "'" + " is too small for Int32, min is " + std::to_string(std::numeric_limits<std::int32_t>::min()));
		}
		else if (tmp > std::numeric_limits<std::int32_t>::max()){
			my_str << std::fixed << std::setprecision(0) << tmp;
			throw OverException("'" + my_str.str() + "'" + " is too big for Int32, max is " + std::to_string(std::numeric_limits<std::int32_t>::max()));
		}
	}
	catch (std::out_of_range &e){
		throw e;
	}
	Int32 		*obj = new Int32(value);
	return (obj);
}

IOperand const * Factory::createFloat (std::string const& value) const{
	std::stringstream 	my_str;
	try{
		double tmp;

		tmp = stod(value);
		if (tmp < std::numeric_limits<float>::lowest()){
			my_str << std::defaultfloat << std::numeric_limits<float>::lowest();
			throw UnderException("'" + std::to_string(stof(value)) + "'" + " is too small for Float, min is " +  my_str.str());
		}
		else if (tmp > std::numeric_limits<float>::max()){
			my_str << std::defaultfloat << std::numeric_limits<float>::max();
			throw OverException("'" + std::to_string(stof(value)) + "'" + " is too big for Float, max is " + my_str.str());
		}
	}
	catch (std::out_of_range &e){
		std::stringstream 	my_str;
		my_str << std::defaultfloat << std::numeric_limits<float>::max();
		throw OverException("'" + value + "'" + " is too big for Float, max is " + my_str.str());
	}
	Float 		*obj = new Float(value);
	return (obj);
}

IOperand const * Factory::createDouble (std::string const& value) const{
	try{
		double tmp;

		std::stringstream 	my_str;
		tmp = stod(value);
		if (tmp < std::numeric_limits<double>::lowest()){
			my_str << std::defaultfloat << std::numeric_limits<double>::lowest();
			throw UnderException("'" + value + "'" + " is too small for Double, min is " + my_str.str());
		}
		else if (tmp > std::numeric_limits<double>::max()){
			my_str << std::defaultfloat << std::numeric_limits<double>::max();
			throw OverException("'" + value + "'" + " is too big for Double, max is " + my_str.str());
		}
	}
	catch (std::out_of_range &e){
		std::stringstream 	my_str;
		my_str << std::defaultfloat << std::numeric_limits<double>::max();
		throw OverException("'" + value + "'" + " is too big for Double, max is " + my_str.str());
	}
	Double 		*obj = new Double(value);
	return (obj);
}

Factory::UnderException::UnderException(std::string str) throw() : std::runtime_error(str){
	return ;
}

Factory::UnderException::~UnderException() throw() {
	return ;	
}

const char* 	Factory::UnderException::UnderException::what() const throw() {
	std::string ret = "Underflow Error : " + std::string(std::runtime_error::what());
	return ret.c_str();
}

Factory::OverException::OverException(std::string str) throw() : std::runtime_error(str){
	return ;
}

Factory::OverException::~OverException() throw() {
	return ;	
}

const char* 	Factory::OverException::OverException::what() const throw() {
	std::string ret = "Overflow Error : " + std::string(std::runtime_error::what());
	return ret.c_str();
}