# ifndef PLASMARIFLE_H
#define PLASMARIFLE_H

#include <iostream>
#include <string>
#include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
	public:
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const &src);
		virtual ~PlasmaRifle(void);

		PlasmaRifle	&operator=(PlasmaRifle const &rhs);

		virtual void		attack(void) const;
	
};

# endif