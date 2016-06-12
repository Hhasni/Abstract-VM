#ifndef INT16_HPP
# define INT16_HPP

# include "IOperand.hpp"
# include "Factory.hpp"

class Int16 : public IOperand
{
	public:
		Int16();
		Int16(std::string const& val);
		virtual 		~Int16();
		int16_t	 		my_val;
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