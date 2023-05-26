#include "iter.hpp"

template <typename T>
void iter(T *array, int length, T f(T e))
{
	for (int i = 0; i < length; i++)
	{
		array[i] = f(array[i]);
	}
}

int takeSquare(int nb)
{
	int square = nb * nb;
	return square;
}

int takeNewValue(int a)
{
	int b = a * (a + 1);
	return b;
}

int main(void)
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::cout << "----------------------" << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << array[i] << std::endl;
	
	std::cout << "----------------------" << std::endl;

	iter(array, 10, &takeSquare);
	for (int i = 0; i < 10; i++)
		std::cout << array[i] << std::endl;

	std::cout << "----------------------" << std::endl;

	iter(array1, 10, &takeNewValue);
	for (int i = 0; i < 10; i++)
		std::cout << array1[i] << std::endl;
	
	return 0;
}
