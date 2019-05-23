/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:54:29 by cjulliar          #+#    #+#             */
/*   Updated: 2019/05/23 17:54:31 by cjulliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	_fract = 8;

Fixed::Fixed(void): _point(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const point)
{
	std::cout << "Int constructor called" << std::endl;
	// this->_point = toInt(point); // ????
	return ;
}
Fixed::Fixed(float const point)
{
	std::cout << "Float constructor called" << std::endl;
	// this->_point = toFloat(point); // ???
	return;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & 	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_point = rhs.getRawBits();
	return *this;
}

int 		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return	this->_point;
}
void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_point = raw;
	return ;
}

float		Fixed::toFloat(void) const
{
	float rep;

	rep = 4.2;
	return rep;
}

int			Fixed::toInt(void) const
{
	int rep;

	rep = 42;
	return rep;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << "sth" << i.getRawBits();

	return o;
}









