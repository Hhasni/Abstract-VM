#ifndef INTHEIGHT_HPP
# define INTHEIGHT_HPP

# include "IOperand.hpp"
# include "Factory.hpp"

class IntHeight : public IOperand
{
	public:
		IntHeight();
		IntHeight(std::string const& val);
		virtual 		~IntHeight();
		int8_t 			my_val;
		int 			_my_pre;
		eOperandType 	_my_type;

		IOperand const*			operator+(IOperand const & rhs) const;
		IOperand const*			operator-(IOperand const & rhs) const;
		IOperand const*			operator*(IOperand const & rhs) const;
		IOperand const*			operator/(IOperand const & rhs) const;
		IOperand const*			operator%(IOperand const & rhs) const;

		int 					getPrecision() const;
		eOperandType			getType() const;
		std::string const & 	toString() const;
};

#endif