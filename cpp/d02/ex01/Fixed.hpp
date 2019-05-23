#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const point);
		Fixed(float const point);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		static const int	_fract;
		int					_point;
};

std::ostream &		operator<<(std::ostream & o, Fixed const & i);

# endif