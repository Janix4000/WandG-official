#include "Enemy.h"



Enemy::Enemy(int level)
{
	this->level = level;
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
	sp = 5;
	lootChance = float(dice::rollDice(80)) / 100.0f;
}


Enemy::~Enemy()
{
}

int Enemy::getDamage() const
{
	return this->strength + dice::rollD6();
}

void Enemy::takeDamage(int damage)
{
	hp -= damage;
}
