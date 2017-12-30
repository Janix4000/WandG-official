#include "Entity.h"

Entity::~Entity()
{
}

Entity::Entity( const std::string name , int lvl)
{
	this->level = lvl;
	this->name = name;
}




//Functions

/*
void Entity::levelUp()
{
	while (this->exp >= this->expToNext)
	{
		exp -= expToNext;
		level++;
		expToNext = 16 * (pow(level, 3) - 6 * pow(level, 2) + (17 * level) - 11);
	}
}
*/

void Entity::drawSheet() const
{
	std::cout << std::endl
		<< "Imie: " << name << std::endl
		<< "Hp: " << hp << "/" << maxHP << std::endl
		<< "Punkty Akcji: " << pa << "/" << maxPA << std::endl
		<< std::endl
		<< "Sila: " << strength << std::endl
		<< "Intelekt: " << intelligence << std::endl
		<< "Budowa: " << vitality << std::endl
		<< "Zrecznosc: " << dexterity << std::endl
		<< "Charyzma: " << charisma << std::endl
		<< "Roztropnosc: " << prudence << std::endl
		<< std::endl
		<< "Level: " << level << std::endl
		//<< "Exp: " << exp << "/" << expToNext << std::endl
		<< std::endl << std::endl;
}

void Entity::addLevel(int nTimes)
{
	for (int i = 0; i < nTimes; i++)
	{
		level++;
	}
}

void Entity::takeHeal(int heal)
{
	if (isAlive())
	{
		std::cout << getName() << " zostal hilniety za " << heal << " punktow.\n";
		hp += heal;
		if (hp > maxHP)
		{
			hp = maxHP;
		}
	}
	else
	{
		std::cout << "Martwego nie uleczysz...\n";
	}
	out::writePressEnter();
}

void Entity::takeDamage(int dam)
{
	this->hp -= dam;
	std::cout << getName() << " otrzymal " << dam << " punktow obrazen.\n";
	if (!isAlive())
	{
		std::cout << "To byl smiertelny cios...\n";
	}
	out::writePressEnter();
}

int Entity::getDamage(int additionalDmg) const
{
	return this->strength + this->atack + dice::rollD6() + additionalDmg;
}

