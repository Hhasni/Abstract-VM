#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <iostream>
# include <cmath>
# include <iomanip>
enum eOperandType
{
	e_Int8 = 0,
	e_Int16,
	e_Int32,
	e_Float,
	e_Double
	
};

class IOperand {

	public:
		virtual	int 				getPrecision(void)	const = 0;// Precision of the type of the instance
		virtual eOperandType 		getType(void)		const = 0;// Type of the instance

		virtual	IOperand const * 	operator+(IOperand const & rhs) const = 0;// Sum
		virtual	IOperand const * 	operator-(IOperand const & rhs) const = 0;// Difference
		virtual	IOperand const * 	operator*(IOperand const & rhs) const = 0;// Product
		virtual	IOperand const * 	operator/(IOperand const & rhs) const = 0;// Quotient
		virtual	IOperand const * 	operator%(IOperand const & rhs) const = 0;// Modulo

		virtual std::string const & toString(void) 		const = 0;// String representation of the instance

		virtual ~IOperand(void) {}
};

#endif