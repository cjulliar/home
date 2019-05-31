#include "Span.hpp"

Span::Span(void)
{
	_v.reserve(0);
	return ;
}
Span::Span(unsigned int const length)
{
	_v.reserve(length);
	_shortest = -1;
	_longest = -1;
	return ;
}
Span::Span(Span const &src)
{
	*this = src;
	return ;
}
Span::~Span(void)
{
	return ;
}

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
		_v = rhs.getV();
	return *this;
}

std::vector<int> Span::getV(void) const
{
	return _v;
}

void	Span::addNumber2(int n)
{
	if (_v.size() < _v.capacity())
	{
		if (_v.size() >= 1)
		{
			for (unsigned long i = 0; i < _v.size(); ++i)
			{
				if (abs(_v[i] - n) < _shortest || _shortest == -1)
					_shortest = abs(_v[i] - n);
				if (abs(_v[i] - n) > _longest || _longest == -1)
					_longest = abs(_v[i] - n);
			}
		}
		_v.push_back(n);

	}
	else
		throw Span::OverAddException();
}

void	Span::addNumber(int n)
{
	try
	{
		addNumber2(n);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
int		Span::shortestSpan2(void)
{
	if(_v.size() < 2)
		throw Span::notEnoughtOfException();
	else
		return _shortest;
}
int		Span::longestSpan2(void)
{
	if(_v.size() < 2)
		throw Span::notEnoughtOfException();
	else
		return _longest;
}
int		Span::shortestSpan(void)
{
	try
	{
		return (shortestSpan2());
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return -1;
}
int		Span::longestSpan(void)
{
	try
	{
		return (longestSpan2());
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return -1;
}
