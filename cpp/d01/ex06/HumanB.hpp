#ifndef HUMANB_H
# define HUMANB_H
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string);
		~HumanB(void);

		void		setWeapon(Weapon&);
		void		attack();

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif