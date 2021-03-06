#pragma once
#include "Weapon.h"
#include "Armor.h"
#include <vector>
#include <cassert>

class Inventory
{
public:
	Inventory();
	~Inventory();

	//Accesors

	inline int size() const { return int(itemVec.size()); }

	//Functions

	void addItem(const Item& item);
	inline void printDebbug() const
	{
		size_t cap = itemVec.size();
		for (unsigned int i = 0; i < cap; i++)
		{
			std::cout << itemVec[i]->getName() << std::endl;
		}
	}
	
	//Operators

	Inventory& operator=(const Inventory& rhs);
	Inventory(const Inventory& rhs);
	Item& operator[](int index);
	const Item& operator[](int index) const;

private:
	std::vector<Item*> itemVec;
};

