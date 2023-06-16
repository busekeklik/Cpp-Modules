#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int>stack;
    public:
        std::string line;
        std::string acceptableValue;
        std::string operators;

        RPN();
		~RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &rpn);

        void fourTransactions(std::string line);
        bool charExistsInString(const std::string& str, char ch);
};
#endif