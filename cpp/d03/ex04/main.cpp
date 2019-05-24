#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	FragTrap frag1("frag");
	ScavTrap scav2("Scav");
	ClapTrap clap3("Clap");
	NinjaTrap ninja4("Ninja");
	SuperTrap super5("Super");

	std::cout << std::endl;

	super5.rangeAttack(frag1.getName());
	frag1.takeDamage(super5.getRangeAttackDmg());

	std::cout << std::endl;

	super5.meleeAttack(scav2.getName());
	scav2.takeDamage(super5.getMeleeAttackDmg());

	// std::cout << std::endl;

	// clap3.meleeAttack(ninja4.getName());
	// ninja4.takeDamage(clap3.getMeleeAttackDmg());

	std::cout << std::endl;

	super5.vaulthunter_dot_exe(clap3.getName());
	clap3.takeDamage(super5.getVaulthunterDotExeDmg());


	std::cout << std::endl;

	super5.ninjaShoebox(ninja4.getName());

	std::cout << std::endl;

	return 0;
}