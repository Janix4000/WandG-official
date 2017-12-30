#include "Character.h"



Character::Character(const std::string& name)
	:
	Entity(name)
{
	maxHP = 40;
	hp = getMaxtHP();
}


Character::~Character()
{
}

//Functions


void Character::levelUp()
{
	while (this->exp >= this->expToNext)
	{
		exp -= expToNext;
		Entity::addLevel();
		int lvl = getLevel();
		expToNext = 16 * ( pow(lvl, 3) - 6* pow(lvl, 2) + (17 * lvl) - 11);
	}
}



void Character::addExp(int add)
{
	this->exp += add;
	levelUp();
}
