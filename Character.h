#pragma once
#include <iomanip>
#include "Entity.h"


class Character
	: public Entity
{
public:
	Character(const std::string& name = "");
	~Character();


	//Functions
	void levelUp();

	void atack( Entity* target) override;

	//Accesors

	inline const int& getExp() const { return this->exp; }
	inline const int& getExpToNext() const { return this->expToNext; }
	
	//Modifiers

	void addExp(int add);

private:

	int exp;
	int expToNext;
	//int level;

	Inventory inventory;

};

