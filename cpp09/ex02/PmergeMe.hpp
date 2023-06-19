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
// template <typename Container>

// void MergeSort(Container& container, typename Container::iterator left, typename Container::iterator right);
// void Merge(Container& container, typename Container::iterator left, typename Container::iterator mid, typename Container::iterator right) {
// template <typename T>
// void Merge(T& container, typename T::iterator left, typename T::iterator mid, typename T::iterator right) {
//     T merged;
//     typename T::iterator it1 = left;
//     typename T::iterator it2 = mid;
    
//     while (it1 != mid && it2 != right) {
//         if (*it1 <= *it2) {
//             merged.push_back(*it1);
//             ++it1;
//         } else {
//             merged.push_back(*it2);
//             ++it2;
//         }
//     }
    
//     merged.insert(merged.end(), it1, mid);
//     merged.insert(merged.end(), it2, right);
    
//     typename T::iterator mergedIt = merged.begin();
//     typename T::iterator containerIt = left;
//     while (mergedIt != merged.end() && containerIt != right) {
//         *containerIt = *mergedIt;
//         ++mergedIt;
//         ++containerIt;
//     }
// }

// template <typename T>
// void MergeSort(T& container, typename T::iterator left, typename T::iterator right) {
//     if (right - left > 1) {
//         typename Container::iterator mid = left + (right - left) / 2;
//         MergeSort(container, left, mid);
//         MergeSort(container, mid, right);
//         Merge(container, left, mid, right);
//     }
// }

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