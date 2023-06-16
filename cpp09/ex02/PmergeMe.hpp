#ifndef PMERGME_HPP
# define PMERGE_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
    private:
        std::vector <int> vectorn;
        std::deque <int> dequen;
    public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe & origin);
	PmergeMe & operator=(const PmergeMe & origin);

    void printDeque();
    void printVector();
    void sort(char **str);

}
#endif