#include "Span.hpp"

int main()
{
	Span sp(5);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.addNumber(3);
	sp.addNumber(42);
	sp.addNumber(92);
	sp.addNumber(13);
	sp.addNumber(412);

	sp.addNumber(2);
	sp.addNumber(13);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << "\n\n"<< std::endl;


	Span lot(10000);
	srand (time(NULL));
	for (int i = 0; i < 10000; ++i)
	{
		lot.addNumber(std::rand() % 420);	
	}
	lot.addNumber(std::rand() % 420000);	

	std::cout << lot.shortestSpan() << std::endl;
	std::cout << lot.longestSpan() << std::endl;

	return 0;
}