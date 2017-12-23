#pragma once
#include <iomanip>
#include "Inventory.h"
#include "SpellCodex.h"

class Character
{
public:
	Character(std::string& name);
	~Character();

	//Enums
	/*
	enum class Size
	{
		tiny,
		small,
		medium,
		big,
		large
	};
	*/
	//Functions

	void levelUp();
	void drawSheet() const;
	void takeDamage(int dam);
	template<typename S>
	inline void useSpell(S spell, Character& target)
	{
		spell(*this, target);
	}

	//Accesors

	inline const std::string& getName() const { return this->name; }
	inline const int& getHP() const { return this->hp; }
	inline const int& getMaxtHP() const { return this->maxHP; }
	inline const int& getPA() const { return this->pa; }
	inline const int& getMaxPA() const { return this->maxPA; }
	//inline const Size& getSizet() const { return this->size; }
	inline const int& getMana() const { return this->mana; }
	inline const int& getMaxManaPA() const { return this->maxMana; }
	inline bool isAlive() const { return hp >= 0; }
	inline bool didAtack() const { return didHeAtack; }

	inline const int& getStrenght() const { return this->strength; }
	inline const int& getIntelligence() const { return this->intelligence; }
	inline const int& getDexterity() const { return this->dexterity; }
	inline const int& getCharisma() const { return this->charisma; }
	inline const int& getPrudence() const { return this->prudence; }

	inline const int& getExp() const { return this->exp; }
	inline const int& getExpToNext() const { return this->expToNext; }
	inline const int& getLevel() const { return this->level; }
	

	//Modifiers

	void addExp(int add);
	inline void addMana(int add) 
	{
		mana += add;  if (mana < 0) mana = 0; else if (mana > maxMana)mana = maxMana;
	}
	inline void addPA(int add)
	{
		pa += add;  if (pa < 0) pa = 0; else if (pa > maxPA)pa = maxPA;
	}
	inline void reverseAtack()
	{
		didHeAtack = !didHeAtack;
	}


private:
	std::string name;
	int hp;
	int maxHP;
	int pa;
	int maxPA;
	//Size size;
	int mana;
	int maxMana;


	int strength;
	int intelligence;
	int vitality;
	int dexterity;
	int charisma;
	int prudence;


	int exp;
	int expToNext;
	int level;

	Inventory inventory;
	Weapon weapon;
	Armor armor;

	bool didHeAtack = false;

};


