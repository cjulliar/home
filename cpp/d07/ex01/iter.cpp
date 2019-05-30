#include <iostream>
#include <string>

template<typename V>
void	iter(V *array, int len, void (*foo)(V const &))
{
	for (int i = 0; i < len; ++i)
	{
		foo(array[i]);
	}
	return ;
};

template<typename V>
void	my_print(V const &v)
{
	std::cout << v << std::endl;
	return ;
}

int main()
{
	std::string Sativa[] = {
		"Haze",
		"Jack Herer",
		"Sour Diesel",
		"Harlequin",
		"Acapulco Gold"
	};
	float number[] = {0.42f,4.2f,42.0f,420.0f,4200.0f};

	iter(Sativa, (sizeof(Sativa)/sizeof(*Sativa)), my_print);
	iter(number, (sizeof(number)/sizeof(*number)), my_print);
	return 0;
}