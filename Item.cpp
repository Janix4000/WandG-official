#include "Item.h"



Item::Item(const std::string& name, Rarity rarity, int sellValue , int buyValue )
{
	this->name = name;
	this->sellValue = sellValue; 
	this->buyValue = buyValue;
	this->rarity = rarity;
}


Item::~Item()
{
}
