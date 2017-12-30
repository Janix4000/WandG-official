#pragma once
#include "Item.h"
class Armor :
	public Item
{
public:

	//Enums

	enum class Type
	{
		none,
		helmet,
		chect,
		pants
	};

	Armor(const std::string& name = "NONE", Rarity rarity = Rarity::none, int defence = 0,
		Type type = Type::none, int sellValue = 0, int buyValue = 0);
	~Armor();

	//Functions

	std::string toString() const;

	//Pure Virtual

	virtual Armor* clone() const;

private:
	int defence;
	Type type;
};

