#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>


template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() : std::stack<T>(){}
	MutantStack &operator=(const MutantStack &other)
	{
		std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }
};

#endif