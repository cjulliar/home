#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav1("Player1");
	ScavTrap scav2("Player2");
	std::cout << std::endl;
	scav1.rangeAttack(scav2.getName());
	scav2.takeDamage(scav1.getRangeAttackDmg());
	std::cout << std::endl;
	scav2.meleeAttack(scav1.getName());
	scav1.takeDamage(scav2.getMeleeAttackDmg());
	std::cout << std::endl;
	scav1.beRepaired(12);
	scav2.beRepaired(35);
	std::cout << std::endl;
	scav1.challengeNewcomer(scav2.getName());
	scav2.challengeNewcomer(scav1.getName());
	std::cout << std::endl;
	return 0;
}