#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Item.h"

class Character
{
public:
	Character();
	~Character();

	//Enums

	enum class Size
	{
		tiny,
		small,
		medium,
		big,
		large
	};

	//Functions

	void init( const std::string& name);
	void levelUp();
	void drawSheet() const;

	//Accesors

	inline const std::string& getName() const { return this->name; }
	inline const int& getHP() const { return this->hp; }
	inline const int& getMaxtHP() const { return this->maxHP; }
	inline const int& getPA() const { return this->pa; }
	inline const int& getMaxPA() const { return this->maxPA; }
	inline const Size& getSizet() const { return this->size; }

	inline const int& getStrenght() const { return this->strength; }
	inline const int& getIntelligence() const { return this->intelligence; }
	inline const int& getDexterity() const { return this->dexterity; }
	inline const int& getCharisma() const { return this->charisma; }
	inline const int& getPrudence() const { return this->prudence; }

	inline const int& getExp() const { return this->exp; }
	inline const int& getExpToNext() const { return this->expToNext; }
	inline const int& getLevel() const { return this->level; }
	

	//Modifiers

private:
	std::string name;
	int hp;
	int maxHP;
	int pa;
	int maxPA;
	Size size;


	int strength;
	int intelligence;
	int vitality;
	int dexterity;
	int charisma;
	int prudence;


	int exp;
	int expToNext;
	int level;

};

