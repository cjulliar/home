#include "Fixed.hpp"

const int	_fract = 8;

Fixed::Fixed(void): _point(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const point): _point(point)
{
	std::cout << "Parametric constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_point = rhs.getRawBits();
	return *this;
}

int 	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	// .8 apres la virgule ? wtf ?
	return	this->_point;
}
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_point = raw;
	return ;
}