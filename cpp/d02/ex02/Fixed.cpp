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

const int    Fixed::_fract = 8;

Fixed::Fixed(void): _point(0)
{
	return ;
}

Fixed::Fixed(int const enter)
{
	this->_point = enter << _fract;
	return ;
}
Fixed::Fixed(float const enter)
{
    this->_point = roundf(enter * (1 << _fract));
	return;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed 		 &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_point = rhs.getRawBits();
	return *this;
}

int 		Fixed::getRawBits(void) const
{
	return	this->_point;
}
void		Fixed::setRawBits(int const raw)
{
	this->_point = raw;
	return ;
}

float		Fixed::toFloat(void) const
{
    return ((float)(this->_point) / (1 << _fract));
}

int			Fixed::toInt(void) const
{
    return ((int)(this->_point) / (1 << _fract));

}

bool		Fixed::operator>(Fixed const &rhs) const
{
	return (this->_point > rhs._point);
}
bool		Fixed::operator<(Fixed const &rhs) const
{
	return (this->_point < rhs._point);
}
bool		Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_point >= rhs._point);
}
bool		Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_point <= rhs._point);
}
bool		Fixed::operator==(Fixed const &rhs) const
{
	return (this->_point == rhs._point);
}
bool		Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_point != rhs._point);
}

Fixed		Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed		Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed		Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed		Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed		&Fixed::min(Fixed &val1, Fixed &val2)
{
	if (val1 < val2)
		return val1;
	else
		return val2;
}
const Fixed		&Fixed::min(Fixed const &val1, Fixed const &val2)
{
	if (val1 < val2)
		return val1;
	else
		return val2;
}
Fixed		&Fixed::max(Fixed &val1, Fixed &val2)
{
	if (val1 > val2)
		return val1;
	else
		return val2;
}
const Fixed		&Fixed::max(Fixed const &val1, Fixed const &val2)
{
	if (val1 > val2)
		return val1;
	else
		return val2;
}

std::ostream &operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);

	return o;
}