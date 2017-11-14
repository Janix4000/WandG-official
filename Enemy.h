#pragma once
#include "Character.h"
#include "Dice.h"

class Enemy
{
public:
	Enemy(int level = 0);
	~Enemy();

	//Getters

	inline const int& getHP() const { return this->hp; }
	inline const int& getMaxtHP() const { return this->maxHP; }
	inline const int& getPA() const { return this->pa; }
	inline const int& getMaxPA() const { return this->maxPA; }

	inline const int& getStrenght() const { return this->strength; }
	inline const int& getIntelligence() const { return this->intelligence; }
	inline const int& getDexterity() const { return this->dexterity; }
	inline const int& getCharisma() const { return this->charisma; }
	inline const int& getPrudence() const { return this->prudence; }

	inline const int& getLevel() const { return this->level; }
	inline const float& getLootChance() const { return this->lootChance; }

	//Functions

	inline bool isAlive() const { return hp > 0; }
	int getDamage() const;
	void takeDamage(int damage);

private:
	int hp;
	int maxHP;
	int pa;
	int maxPA;
	int sp;


	int strength;
	int intelligence;
	int vitality;
	int dexterity;
	int charisma;
	int prudence;

	int level;
	float lootChance;
};

