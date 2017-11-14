#ifndef DICE_H
#define DICE_H

#include <cstdlib>

int rollDice(int dice)
{
	return rand() % dice + 1;
}

int rollD6()
{
	return rollDice(6);
}

int rollD12()
{
	return rollDice(12);
}

int rollD20()
{
	return rollDice(20);
}
#endif