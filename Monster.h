#pragma once
#include "Character.h"
class Monster :
	public Entity
{
public:
	Monster(const std::string& name="", int lvl = 1)
		:
		Entity(name, lvl)
	{
		this->maxHP = level * 10 + dice::rollD6();
		this->hp = maxHP;

		this->maxPA = level * 6 + dice::rollD6();
		this->pa = maxPA;

		this->strength = level * 2 + dice::rollD6();
		this->intelligence = level * 2 + dice::rollD6();
		this->vitality = level * 2 + dice::rollD6();
		this->dexterity = level * 2 + dice::rollD6();
		this->charisma = level * 2 + dice::rollD6();
		this->prudence = level * 2 + dice::rollD6();
	}

	virtual void atack( Character& target) = 0;

private:
	float dropRate = 0.f;

};

