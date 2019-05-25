#ifndef ISQUAD_HPP
#define ISQUAD_HPP

#include <iostream>
#include "ISpaceMarine.hpp"

class ISquad
{
	public:
		virtual ~ISquad() {return;}
		virtual int getCount() const = 0;
		virtual ISpaceMarine* getUnit(int) const = 0;
		virtual int push(ISpaceMarine*) = 0;
};

#endif