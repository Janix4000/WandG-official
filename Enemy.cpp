#include "Enemy.h"



Enemy::Enemy(int level)
{
	this->level = level;
	this->maxHP = level * 10 + rollD6();
	this->hp = maxHP;
	
	this->maxPA = level * 6 + rollD6();
	this->pa = maxPA;

	this->strength = level * 2 + rollD6();
	this->intelligence = level * 2 + rollD6();
	this->vitality = level * 2 + rollD6();
	this->dexterity = level * 2 + rollD6();
	this->charisma = level * 2 + rollD6();
	this->prudence = level * 2 + rollD6();
	sp = 5;
	lootChance = float(rollDice(80)) / 100.0f;
}


Enemy::~Enemy()
{
}

int Enemy::getDamage() const
{
	return this->strength + rollD6();
}

void Enemy::takeDamage(int damage)
{
	hp -= damage;
}
