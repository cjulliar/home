#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;
	return ;
}
AssaultTerminator::AssaultTerminator(const AssaultTerminator &src)
{
	std::cout << "* teleports from space *" << std::endl;
	*this = src;
	return ;
}
AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I’ll be back ..." << std::endl;
	return ;
}

AssaultTerminator	&AssaultTerminator::operator= (const AssaultTerminator &rhs)
{
	(void)rhs;
	return (*this);
}
ISpaceMarine		*AssaultTerminator::clone(void) const
{
	return (new AssaultTerminator);
}


void 				AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
	return ;
}
void				AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *" << std::endl;
	return ;
}
void				AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
	return ;
}
