#pragma once
#include "Monster.h"

class Goblin : 
	public Monster
{
public:
	Goblin(const std::string& name = "", int lvl = 1);

private:
	int biteDmg = 2;
	int punchDmg = 6;

public:
	void atack(Character& target) override;

private:
	void bite(Character& target);
	void punch(Character& target);


};