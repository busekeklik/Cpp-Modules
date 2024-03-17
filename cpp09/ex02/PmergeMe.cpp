#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe & origin)
{
	*this = origin; 
}

PmergeMe & PmergeMe::operator=(const PmergeMe & th)
{
	this->vectorn = th.vectorn;
	this->dequen = th.dequen;
	return *this;
}

void PmergeMe::numbersCheck(char *s)
{
	std::string str = s;
	if (str[0] == '-')
		throw ("Error");
	if (str.length() > 10 || (str.length() == 10 && str > "2147483647"))
		throw ("Error");
	if (!str.empty() && str.find_first_not_of("0123456789") != std::string::npos)
		throw ("Error");
}


void PmergeMe::printVector()
{
    int i = 0;
	for (std::vector<int>::iterator it = vectorn.begin(); it < vectorn.end(); it++)
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
		nb = std::stoi(str[i]);
		vectorn.push_back(nb);
		dequen.push_back(nb);
		i++;
	}
    std::cout << "Before :";
	printVector();
	start = clock();
    MergeSort(vectorn, 0, vectorn.size() - 1);
	end = clock();
	startTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
	MergeSort(dequen, 0, vectorn.size() - 1);
	end = clock();
	finishTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After :";
	printVector();
	//printDeque();
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of "<< vectorn.size() <<  " elements with std::vector : " << startTime << " us" << std::endl;
	std::cout << "Time to process a range of "<< dequen.size() <<  " elements with std::deque : " << finishTime << " us" << std::endl;
}
