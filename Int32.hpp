#ifndef INT32_HPP
# define INT32_HPP

# include "IOperand.hpp"
# include "Factory.hpp"

class Int32 : public IOperand
{
	public:
		Int32();
		Int32(std::string const& val);
		virtual 		~Int32();
		int32_t	 		my_val;
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