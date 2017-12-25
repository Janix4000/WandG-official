#include "Entity.h"

Entity::~Entity()
{
}

Entity::Entity( const std::string name )
{
	this->name = name;
	this->maxHP = 10;
	this->hp = maxHP;
	this->maxPA = 10;
	this->pa = maxPA;;

	this->strength = 0;
	this->intelligence = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->charisma = 0;
	this->prudence = 0;

	this->level = 1;
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

void Entity::takeDamage(int dam)
{
	this->hp -= dam;
}

int Entity::getDamage() const
{
	return this->strength;
}

