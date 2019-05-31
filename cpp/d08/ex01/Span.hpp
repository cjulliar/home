#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	public:
		Span(void);
		Span(unsigned int const length);
		Span(Span const &src);
		~Span(void);
		Span	&operator=(Span const &rhs);

		void				addNumber(int);
		void				addNumber2(int);
		std::vector<int> 	getV(void) const;
		int					shortestSpan(void);
		int					longestSpan(void);
		int					shortestSpan2(void);
		int					longestSpan2(void);

		class OverAddException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: all numbers are already allowed");
				}
		};
		class notEnoughtOfException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: there is not enough of numbers");
				}
		};
	private:
		std::vector<int>	_v;
		int					_shortest;
		int					_longest;

	
};

#endif