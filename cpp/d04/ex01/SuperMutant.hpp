# ifndef SUPERMUTANT_H
#define SUPERMUTANT_H

#include <iostream>
#include <string>
#include "Enemy.hpp"

class SuperMutant: public Enemy
{
	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const &src);
		virtual ~SuperMutant(void);

		SuperMutant	&operator=(SuperMutant const &rhs);

		virtual void 		takeDamage(int damage);
	
};

# endif