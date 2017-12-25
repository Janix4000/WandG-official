#pragma once


#include "Inventory.h"


class Entity
{
public:
	Entity(const std::string name = "");

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

	inline const int& getLevel() const { return this->level; }


	void takeDamage(int dam);
	int getDamage() const;
	//void levelUp();
	void drawSheet() const;

	//Modifiers

	//void addExp(int add);

private:
	std::string name;
	int hp;
	int maxHP;
	int pa;
	int maxPA;


	int strength;
	int intelligence;
	int vitality;
	int dexterity;
	int charisma;
	int prudence;

	int level;

	Weapon weapon;
	Armor armor;

protected:
	void addLevel(int nTimes = 1);
	void setStatsByLevel();
};

