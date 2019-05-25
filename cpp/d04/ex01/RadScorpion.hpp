# ifndef RADSCORPION_H
#define RADSCORPION_H

#include <iostream>
#include <string>
#include "Enemy.hpp"

class RadScorpion: public Enemy
{
	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const &src);
		virtual ~RadScorpion(void);

		RadScorpion	&operator=(RadScorpion const &rhs);
	
};

# endif