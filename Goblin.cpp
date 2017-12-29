#include "Goblin.h"

Goblin::Goblin(const std::string & name, int lvl)
	:
	Monster("Goblin " + name, lvl)
{
}

void Goblin::atack(Character & target)
{
	int roll = dice::rollD12();
	if (roll <= 4)
	{
		bite(target);
	}
	else if (roll <= 12)
	{
		punch(target);
	}
}

void Goblin::bite(Character & target)
{
	int damage = getDamage(biteDmg);
	int restoredHealth = damage / 3;

	std::cout << "Chuj "<< getName() << " gryzie!\n";
	target.takeDamage(damage);

	std::cout << "Chuj " << getName() << " napelnil brzuszek.\n";
	takeHeal(restoredHealth);
}

void Goblin::punch(Character & target)
{
	int damage = getDamage(punchDmg);

	std::cout << getName() << " zwyzywal matke bohatera " << target.getName() << ".\n"
		<< "Jest tak zazenowany poziomem jego puncha,\n"
		<< "ze nie zauwaza, ze wlasnie oberwal w ryj.\n";

	target.takeDamage(damage);
}
