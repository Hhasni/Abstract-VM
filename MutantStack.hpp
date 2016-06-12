#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	 	typedef std::stack<T> 	my_stack;
		MutantStack & operator=(MutantStack const & src);

	public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(MutantStack const & o): my_stack(o) {}
		typedef typename my_stack::container_type::iterator 	iterator;

		
		// using my_stack::operator=;

		iterator 	begin() { return my_stack::c.begin(); }
		iterator 	end() { return my_stack::c.end() ; }

};

#endif