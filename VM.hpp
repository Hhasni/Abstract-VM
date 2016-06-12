#ifndef VM_HPP
# define VM_HPP

# include "MutantStack.hpp"
# include "IOperand.hpp"
# include "IntHeight.hpp"
# include <stdexcept>

class VM
{
	public:
		VM();
		virtual ~VM();
		MutantStack<const IOperand *>	*_Stack;

		void					Execute(std::string inst);
		void					push(std::string inst) const;
		void					pop();
		void					dump();
		void					assert(std::string inst);
		void					add();
		void					sub();
		void					mul();
		void					div();
		void					mod();
		void					print();
		void					exit();

		eOperandType			getType(std::string inst) const;
		std::string				getValue(std::string inst) const;

		class VMException : public std::runtime_error
		{
			public:
				VMException(std::string str) throw();
				~VMException() throw();
				virtual const char * what() const throw();
				
			private:
				VMException & 	operator=(VMException const & src);
		};
};


#endif