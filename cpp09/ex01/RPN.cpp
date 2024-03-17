#include "RPN.hpp"

RPN::RPN(){
    this->acceptableValue = "0123456789+-/* ";
    this->operators = "+-/*";
}

RPN::~RPN(){
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &rpn)
{
	this->st = rpn.st;
    this->line = rpn.line;
    this->acceptableValue = rpn.acceptableValue;
    this->operators = rpn.operators;
	return *this;
}

bool RPN::charExistsInString(const std::string& str, char ch) 
{
    return str.find(ch) != std::string::npos;
}

std::string RPN::removeSpaces(std::string str) 
{
    std::string result;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            result += str[i];
        }
    }
    return result;
}

void RPN::fourTransactions(std::string line)
{
    for (size_t i = 0; i < line.length(); i++)
	{
		size_t index = this->acceptableValue.find(line[i]);
		if (index == std::string::npos)
        {
			std::cerr << "Error" << std::endl;
            exit(1);
        }
	}
    line = removeSpaces(line);

    for (size_t i = 0; i < line.length(); i++)
    {
        char c = line[i];
        if (isdigit(c))
        {
            int nb = c - '0';
            st.push(nb);
        }
        else if (charExistsInString(this->operators, c) && (st.size() >= 2))
        {
            int nb2 = st.top();
            st.pop();
            int nb1 = st.top();
            st.pop();
            if(nb2 == 0 && c == '/')
                throw("");
            switch (c)
            {
            case '+':
                st.push(nb1 + nb2);
                break;
            case '-':
                st.push(nb1 - nb2);
                break;
            case '*':
                st.push(nb1 * nb2);
                break;
            case '/':
                st.push(nb1 / nb2);
                break;
            }            
        }
    } 
    if (st.size() == 1)
	{
		int result = st.top();
		st.pop();
		std::cout << result << std::endl;
	}
}