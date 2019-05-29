#include "Convert.hpp"

Convert::Convert(void)
{
	return ;
}
Convert::Convert(double const d): _double(d)
{
	return ;
}
Convert::Convert(Convert const &src)
{
	*this = src;
	return ;
}
Convert::~Convert(void)
{
	return ;
}

Convert	&Convert::operator=(Convert const &rhs)
{
	if (this != &rhs)
		_double = rhs.getDouble();
	return *this;
}

double	Convert::getDouble(void) const
{
	return _double;
}
