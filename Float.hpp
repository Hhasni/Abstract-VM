#ifndef FLOAT_HPP
# define FLOAT_HPP

# include "IOperand.hpp"
# include "Factory.hpp"

class Float : public IOperand
{
	public:
		Float();
		Float(std::string const& val);
		virtual 		~Float();
		float 			my_val;
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