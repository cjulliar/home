#include "Convert.hpp"
#include "math.h"
#include <iomanip>



int main(int argc, char const *argv[])
{
	if (argc <= 1)
		return 0;

	std::cout << "string: " << argv[1] << std::endl;
	try
	{
		double str_double = std::stod(argv[1]);
		Convert conv(str_double);
		int		i = conv;
		float	f = conv;
		if (i == -2147483648)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible"<< std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
		}
		std::cout << "double: " << str_double << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
	}
	catch(std::exception &e)
	{
		if (strlen(argv[1]) > 1)
			std::cout << "char: Non displayable" << std::endl;
		else
		{
			char c = argv[1][0];
			std::cout << "char: " << c << std::endl;
		}
		std::cout << "int: 0" << std::endl;
		std::cout << "double: 0.0" << std::endl;
		std::cout << "float: 0.0f" << std::endl;

	}

	return 0;
}