#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad: public ISquad
{
	public:
		Squad(void);
		Squad(const Squad &src);
		~Squad(void);
		Squad &operator= (const Squad &rhs);

		virtual int getCount(void) const;
		virtual ISpaceMarine  *getUnit(int nb) const;
		virtual int push(ISpaceMarine *marine);

	private:
		typedef struct	s_container
		{
			ISpaceMarine		*unit;
			struct s_container	*next;
		}				t_container;

		int			_nbr_units;
		t_container	*_squad;

		void		_copyUnits(const Squad &src);
		void		_destroyUnits(void);
		bool		_unitAlreadyIn(ISpaceMarine *marine, t_container *squad);

};

#endif