#pragma once
#include <string>
#include <iostream>

class Item
{
public:
	//Enums

	enum class Rarity
	{
		none,
		common,
		rare,
		epic,
		legendary
	};

	Item(const std::string& name = "NONE",Rarity rarity = Rarity::none,
		int sellValue = 0, int buyValue = 0);
	~Item();

	//Fuctions

	//Getters

	inline const std::string& getName() const { return name; }
	inline const int& getSellValue() const { return sellValue; }
	inline const int& getBuyValue() const { return buyValue; }
	inline const Rarity& getRarity() const { return rarity; }

	//Pure Virtual

	virtual Item* clone() const = 0;

private:
	int sellValue;
	int buyValue;
	std::string name;
	Rarity rarity;
};

