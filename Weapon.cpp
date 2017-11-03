#include "Weapon.h"



Weapon::Weapon(const std::string& name, Rarity rarity, int damage, int sellValue, int buyValue)
	:
	Item(name, rarity, sellValue, buyValue)
{
	this->damage = damage;
}


Weapon::~Weapon()
{
}

std::string Weapon::toString() const
{
	std::string str = std::to_string(damage) + "\n";
	return str;
}

Weapon * Weapon::clone() const
{
	return new Weapon(*this);
}
