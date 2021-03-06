#pragma once
#include "Item.h"
class Weapon :
	public Item
{
public:
	Weapon(const std::string& name = "NONE", Rarity rarity = Rarity::none, int damage = 0,
		int sellValue = 0, int buyValue = 0);
	~Weapon();

	//Functions

	std::string toString() const;

	//Pure Virtual

	virtual Weapon* clone() const;

private:
	int damage;
};

