#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & origin)
{
	*this = origin; 
}

PmergeMe & PmergeMe::operator=(const PmergeMe & th)
{
	this->vector_ = th.vectorn;
	this->deque_ = th.dequen;
	return *this;
}

void PmergeMe::numbersCheck(char *str)
{

}


void PmergeMe::printVector()
{
    int i = 0;
	for (std::vector<int>::iterator it = vector_.begin(); it < vector_.end(); it++)
	{
		if(i >= 8)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
        i++;
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque()
{
    int i = 0;
	for (std::deque<int>::iterator it = dequen.begin(); it < dequen.end(); it++)
	{
		if(i >= 8)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
        i++;
	}
	std::cout << std::endl;
}

void PmergeMe::sort(char **str)
{
    std::clock_t start, end;
	double startTime, finishTime;
    int i = 1;
    int nb;

    while (str[i])
	{
		numbersCheck(str[i]);
		nb = stoi(str[i]);
		vectorn.push_back(nb);
		dequen.push_back(nb);
		i++;
	}
    std::cout << "Before :";
	printVector();
	start = clock();
    merge_sort(vectorn, 0, vector_.size() - 1);
	end = clock();
	startTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
	merge_sort(dequen, 0, vector_.size() - 1);
	end = clock();
	finishTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After :";
	printVector();
	//printDeque();
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of "<< vectorn.size() <<  " elements with std::vector : " << startTime << " ms\n";
	std::cout << "Time to process a range of "<< dequen.size() <<  " elements with std::list : " << finishTime << " ms\n";
}
