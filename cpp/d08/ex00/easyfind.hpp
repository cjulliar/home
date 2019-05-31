#include <iostream>

template <typename T>
int	easyfind(T const &t, int const n)
{
	for (unsigned long i = 0; i < t.size(); ++i)
	{
		if (t[i] == n)
		{
			std::cout << "The first occurence exist in the " << i+1 <<"e paramter." << std::endl;
			return 1;
		}
	}
	std::cout << "The occurence doesn't exist in this list." << std::endl;
	return -1;
}