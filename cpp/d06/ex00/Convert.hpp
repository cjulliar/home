#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

class Convert
{
	public:
		Convert(void);
		Convert(double	const d);
		Convert(Convert const &src);
		~Convert(void);
		Convert	&operator=(Convert const &rhs);

		double	getDouble(void) const;

		operator int() {return static_cast<int>(_double);}
		operator float() {return static_cast<float>(_double);}
		
	private:
		int			_int;
		double		_double;
		float		_float;		
};

#endif