#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	FragTrap frag1("Player1");
	ScavTrap scav2("Player2");
	ClapTrap clap3("Player3");

	std::cout << std::endl;

	frag1.rangeAttack(clap3.getName());
	clap3.takeDamage(frag1.getRangeAttackDmg());

	std::cout << std::endl;

	scav2.meleeAttack(clap3.getName());
	clap3.takeDamage(scav2.getMeleeAttackDmg());

	std::cout << std::endl;

	clap3.meleeAttack(frag1.getName());
	frag1.takeDamage(clap3.getMeleeAttackDmg());

	std::cout << std::endl;

	frag1.beRepaired(12);
	clap3.beRepaired(35);

	std::cout << std::endl;

	frag1.vaulthunter_dot_exe(clap3.getName());
	clap3.takeDamage(frag1.getVaulthunterDotExeDmg());

	std::cout << std::endl;

	scav2.challengeNewcomer(clap3.getName());

	std::cout << std::endl;

	return 0;
}