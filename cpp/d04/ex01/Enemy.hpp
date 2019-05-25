# ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>

class Enemy
{
	public:
		Enemy(void);
		Enemy(int hp, std::string const &type);
		Enemy(Enemy const &src);
		virtual ~Enemy(void);

		Enemy	&operator=(Enemy const &rhs);

		std::string const	getType(void) const;
		int 				getHP(void) const;

		virtual void 		takeDamage(int damage);

	protected:
		int			_hp;
		std::string	_type;
	
};

# endif