#include "Armor.h"



Armor::Armor(const std::string& name, Rarity rarity, int defence, Type type, int sellValue, int buyValue)
	:
	Item(name, rarity, sellValue, buyValue)
{
	this->defence = defence;
	this->type = type;
}


Armor::~Armor()
{
}

std::string Armor::toString() const
{
	std::string str = std::to_string(defence) + "\n";
	return str;
}

Armor * Armor::clone() const
{
	return new Armor(*this);
}
