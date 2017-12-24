#include "Inventory.h"



Inventory::Inventory()
{
}


Inventory::~Inventory()
{
	unsigned int cap = (int)itemVec.size();
	for (unsigned int i = 0; i < cap; i++)
	{
		delete itemVec[i];
	}
}

void Inventory::addItem(const Item & item)
{
	itemVec.emplace_back(item.clone());
}

Inventory & Inventory::operator=(const Inventory & rhs)
{
	unsigned int cap = (int)itemVec.size();
	for (int i = cap-1; i >= 0; i--)
	{
		delete itemVec[i];
		itemVec.pop_back();
	}

	unsigned int srcCap = (int)rhs.itemVec.size();
	for (unsigned int i = 0; i < srcCap; i++)
	{
		itemVec.emplace_back(rhs.itemVec[i]->clone());
	}
	return *this;
}

Inventory::Inventory(const Inventory & rhs)
{
	unsigned int srcCap = (int)rhs.itemVec.size();
	for (unsigned int i = 0; i < srcCap; i++)
	{
		itemVec.emplace_back(rhs.itemVec[i]->clone());
	}
}

Item & Inventory::operator[](int index)
{
	assert(index >= 0 && index < itemVec.size());
	return *itemVec[index];
}

const Item & Inventory::operator[](int index) const
{
	assert(index >= 0 && index < itemVec.size());
	return *itemVec[index];
}
