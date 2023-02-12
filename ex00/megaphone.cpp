#include <iostream>

using std::cout;
using std::endl;

int main(int ac, char **av)
{
	if (ac < 2)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1; av[i]; i++)
		{
			for(int j = 0; av[i][j]; j++)
				cout << static_cast<char>(toupper(av[i][j]));
		}
	}
	cout<<endl;
	return (0);
}