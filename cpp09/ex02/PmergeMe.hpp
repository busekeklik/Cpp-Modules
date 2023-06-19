#ifndef PMERGME_HPP
# define PMERGME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>

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
    void numbersCheck(char *s);
    
    void sort(char **str);

template< typename T >
	void	MergeSort(T & lst, int beg, int end) {
		int mid;
		if (beg<end)  
		{
			mid = (beg+end)/2;  
			MergeSort(lst, beg, mid);  
			MergeSort(lst, mid+1, end);  
			merge(lst, beg, mid, end);  
		}
	}

	template< typename T >
	void	merge(T & lst, int left, int mid, int right)  {  
		std::vector<int> temp(right - left + 1);
		int i = left, j = mid+1, k = 0;
		while (i <= mid && j <= right) {
			if (lst[i] <= lst[j]) {
				temp[k++] = lst[i++];
			} else {
				temp[k++] = lst[j++];
			}
		}
		while (i <= mid) {
			temp[k++] = lst[i++];
		}
		while (j <= right) {
			temp[k++] = lst[j++];
		}

		for (int p = 0; p < k; p++) {
			lst[left+p] = temp[p];
		}
	}
};

#endif