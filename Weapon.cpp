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
