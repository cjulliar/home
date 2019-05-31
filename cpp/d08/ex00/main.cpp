#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v1;
	v1.push_back(25);
	v1.push_back(42);
	v1.push_back(-52);
	v1.push_back(-6);
	v1.push_back(12);
	v1.push_back(6);
	v1.push_back(753234);
	v1.push_back(0);


	easyfind(v1, 6);
	easyfind(v1, 7);
	easyfind(v1, 0);
	return 0;
}