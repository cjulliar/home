#ifndef PONY_H
# define PONY_H
#include <iostream>

class Pony
{
	public:
		Pony(std::string name);
		~Pony(void);
		
		std::string		getColor(void) const;
		void			setColor(std::string);
		int				getNumberLegs(void) const;
		void			setNumberLegs(int);
		double			getSpeed(void) const;
		void			setSpeed(double);

	private:
		std::string _name;
		std::string	_color;
		int			_numberLegs;
		double		_speed;
};

#endif