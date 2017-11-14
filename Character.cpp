#include "Character.h"



Character::Character()
{
	this->name = "";
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

	this->exp = 0;
	this->level = 1;
	this->expToNext = 100;
}


Character::~Character()
{
}

//Functions

void Character::init(const std::string & name)
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

	this->exp = 0;
	this->level = 1;
	this->expToNext = 16 * (pow(level, 3) - 6 * pow(level, 2) + (17 * level) - 11);
}

void Character::levelUp()
{
	while (this->exp >= this->expToNext)
	{
		exp -= expToNext;
		level++;
		expToNext = 16 * ( pow(level, 3) - 6* pow(level, 2) + (17 * level) - 11);
	}
}

void Character::drawSheet() const
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
		<< "Exp: " << exp << "/" << expToNext << std::endl
		<< std::endl << std::endl;
		

}

void Character::takeDamage(int dam)
{
	this->hp -= dam;
}

int Character::getDamage() const
{
	return this->strength;
}

void Character::addExp(int add)
{
	this->exp += add;
	levelUp();
}
