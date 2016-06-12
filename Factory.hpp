#ifndef FACTORY_HPP
# define FACTORY_HPP

# include "IOperand.hpp"
# include <cstdint>
# include <stdexcept>

class Factory{
	public:
		Factory();

		IOperand const * createOperand(eOperandType type, std::string const & value) const;

		IOperand const * createInt8 (std::string const& value) const;
		IOperand const * createInt16 (std::string const& value) const;
		IOperand const * createInt32 (std::string const& value) const;
		IOperand const * createFloat (std::string const& value) const;
		IOperand const * createDouble (std::string const& value) const;

		virtual ~Factory();

		class UnderException : public std::runtime_error
		{
			public:
				UnderException(std::string str) throw();
				~UnderException() throw();
				virtual const char * what() const throw();
				
			private:
				UnderException & 	operator=(UnderException const & src);
		};

		class OverException : public std::runtime_error
		{
			public:
				OverException(std::string str) throw();
				~OverException() throw();
				virtual const char * what() const throw();
				
			private:
				OverException & 	operator=(OverException const & src);
		};
};

#endif