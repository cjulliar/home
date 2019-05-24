#include "FragTrap.hpp"

int main()
{
	FragTrap frag1("Player1");
	FragTrap frag2("Player2");
	std::cout << std::endl;
	frag1.rangeAttack(frag2.getName());
	frag2.takeDamage(frag1.getRangeAttackDmg());
	std::cout << std::endl;
	frag2.meleeAttack(frag1.getName());
	frag1.takeDamage(frag2.getMeleeAttackDmg());
	std::cout << std::endl;
	frag1.beRepaired(12);
	frag2.beRepaired(35);
	std::cout << std::endl;
	frag1.vaulthunter_dot_exe(frag2.getName());
	frag2.takeDamage(frag1.getVaulthunterDotExeDmg());
	std::cout << std::endl;
	frag2.vaulthunter_dot_exe(frag1.getName());
	frag1.takeDamage(frag2.getVaulthunterDotExeDmg());
	std::cout << std::endl;
	return 0;
}