#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5); 
    mstack.push(17);

    std::cout << mstack.top() << std::endl; 
    std::cout <<" --------------" << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;
    std::cout <<" --------------" << std::endl;

    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737); //[...] 
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << *it << std::endl;
    ++it;
    std::cout <<" --------------" << std::endl;
    std::cout << *it << std::endl;
    --it;
    std::cout <<" --------------" << std::endl;

    std::cout << *it << std::endl;
    std::cout <<" --------------" << std::endl;

    while (it != ite) {
        std::cout << *it << std::endl;
    ++it; 
    }

    std::stack<int> s(mstack);

    return 0;
}


/*

int main() {
    MutantStack<int> mutantStack;

    mutantStack.push(1);
    mutantStack.push(2);
    mutantStack.push(3);
    mutantStack.push(4);
    mutantStack.push(5);

    // Using iterators to print the elements
    std::cout << "Elements of MutantStack: ";
    for (const auto& element : mutantStack) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Testing with std::list
    std::list<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);

    // Using iterators to print the elements
    std::cout << "Elements of std::list: ";
    for (const auto& element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/