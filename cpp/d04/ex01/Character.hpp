# ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		virtual ~Character(void);

		Character			&operator=(Character const &rhs);

		void				recoverAP(void);
		void				equip(AWeapon* aweapon);
		void				attack(Enemy* enemy);
		std::string const	getName(void) const;
		int					getAp(void) const;
		AWeapon				*getAweapon(void) const;

	protected:
		std::string	_name;
		AWeapon 	*_aweapon;
		int			_ap;
	
};

std::ostream				&operator<<(std::ostream &out, const Character &rhs);

# endif