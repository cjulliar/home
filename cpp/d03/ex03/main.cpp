#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	FragTrap frag1("frag");
	ScavTrap scav2("Scav");
	ClapTrap clap3("Clap");
	NinjaTrap ninja4("Ninja");


	std::cout << std::endl;

	ninja4.rangeAttack(frag1.getName());
	frag1.takeDamage(ninja4.getRangeAttackDmg());

	std::cout << std::endl;

	ninja4.meleeAttack(scav2.getName());
	scav2.takeDamage(ninja4.getMeleeAttackDmg());

	std::cout << std::endl;

	clap3.meleeAttack(ninja4.getName());
	ninja4.takeDamage(clap3.getMeleeAttackDmg());

	std::cout << std::endl;

	frag1.beRepaired(12);
	clap3.beRepaired(35);

	std::cout << std::endl;

	ninja4.ninjaShoebox(clap3.getName());

	std::cout << std::endl;

	return 0;
}