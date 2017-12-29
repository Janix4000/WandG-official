#pragma once


#include "Inventory.h"
#include "Dice.h"
#include "Functions.h"


class Entity
{
public:
	Entity(const std::string name = "", int lvl = 1);

	virtual ~Entity() = 0;

	inline const std::string& getName() const { return this->name; }
	inline const int& getHP() const { return this->hp; }
	inline const int& getMaxtHP() const { return this->maxHP; }
	inline const int& getPA() const { return this->pa; }
	inline const int& getMaxPA() const { return this->maxPA; }
	inline bool isAlive() const { return this->hp > 0; }

	inline const int& getStrenght() const { return this->strength; }
	inline const int& getIntelligence() const { return this->intelligence; }
	inline const int& getDexterity() const { return this->dexterity; }
	inline const int& getCharisma() const { return this->charisma; }
	inline const int& getPrudence() const { return this->prudence; }

	inline const int& getAtack() const { return this->atack; }
	inline const int& getDefence() const { return this->defence; }
	inline const int& getMagicPower() const { return this->magicPower; }

	inline const int& getLevel() const { return this->level; }

	void takeHeal(int heal);
	void takeDamage(int dam);
	int getDamage(int additionalDmg = 0) const;
	//void levelUp();
	void drawSheet() const;

	//Modifiers

	//void addExp(int add);

protected:
	std::string name;
	int maxHP = 10;
	int hp =  maxHP;
	int maxPA = 10;
	int pa = maxPA;

	int strength = 1;
	int intelligence = 1;
	int vitality = 1;
	int dexterity = 1;
	int charisma = 1;
	int prudence = 1;

	int level;

	Weapon weapon;
	Armor armor;

	int defence = 0;
	int atack = 0;
	int magicPower = 0;

protected:
	void addLevel(int nTimes = 1);
	void setStatsByLevel();
};

