#ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include "IOperand.hpp"
# include "Factory.hpp"

class Double : public IOperand
{
	public:
		Double();
		Double(std::string const& val);
		virtual 		~Double();
		double 			my_val;
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