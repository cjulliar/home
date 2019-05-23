#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int const enter);
		Fixed(float const enter);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed 		&operator=(Fixed const &rhs);

		int 		getRawBits(void) const;
		void		setRawBits(int const raw);

		int			toInt(void) const;
		float		toFloat(void) const;

		bool 		operator>(Fixed const &rhs) const;
		bool 		operator<(Fixed const &rhs) const;
		bool 		operator>=(Fixed const &rhs) const;
		bool 		operator<=(Fixed const &rhs) const;
		bool 		operator==(Fixed const &rhs) const;
		bool 		operator!=(Fixed const &rhs) const;

		Fixed 		operator+(Fixed const &rhs) const;
		Fixed 		operator*(Fixed const &rhs) const;
		Fixed 		operator-(Fixed const &rhs) const;
		Fixed 		operator/(Fixed const &rhs) const;

		static Fixed		&min(Fixed &val1, Fixed &val2);
		static const Fixed	&min(Fixed const &val1, Fixed const &val2);
		static Fixed		&max(Fixed &val1, Fixed &val2);
		static const Fixed	&max(Fixed const &val1, Fixed const &val2);


	private:
		static const int	_fract;
		int					_point;
};

std::ostream &		operator<<(std::ostream & o, Fixed const & i);

# endif