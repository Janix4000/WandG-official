#pragma once
#include "Goblin.h"
#include <stdio.h>

class Team
{
public:
	Team(const std::string& name);
	~Team();
	bool areAlive()const;
	Character& operator[](int index)
	{
		return characters[index];
	}
	const Character& operator[](int index) const
	{
		return characters[index];
	}
	size_t size()const
	{
		return characters.size();
	}

	void createCharacter();
	void charactersMenu();
	void addExpToCharacter();

	inline const std::string& getName()const { return this->name; }
private:
	std::string name;
	std::vector<Character> characters;
	int drawCharMenu()const;
};

