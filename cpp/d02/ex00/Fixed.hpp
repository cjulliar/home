#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const point);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		static const int	_fract;
		int					_point;
};

# endif