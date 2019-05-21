#include "Pony.hpp"

void	ponyOnTheHeap()
{
	Pony* my_pony = new Pony("My litle pony");
	my_pony->setColor("pink");
	my_pony->setNumberLegs(4);
	my_pony->setSpeed(13.56);
	std::cout << "He is "<< my_pony->getColor() << " and he can run to " << my_pony->getSpeed() << "mph with his " << my_pony->getNumberLegs() << " legs." << std::endl;
	delete my_pony ;
	return ;
}

void	ponyOnTheStack()
{
	Pony my_pony = Pony("Pony pony run run");
	my_pony.setColor("brown");
	my_pony.setNumberLegs(2);
	my_pony.setSpeed(9.04);
	std::cout << "He is "<< my_pony.getColor() << " and he can run to " << my_pony.getSpeed() << "mph with his " << my_pony.getNumberLegs() << " legs." << std::endl;
	return ;
}

int		main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}