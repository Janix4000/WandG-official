#ifndef DICE_H
#define DICE_H

#include <cstdlib>

namespace dice
{
	inline int rollDice(int dice)
	{
		return rand() % dice + 1;
	}

	inline int rollD6()
	{
		return rollDice(6);
	}

	inline int rollD12()
	{
		return rollDice(12);
	}

	inline int rollD20()
	{
		return rollDice(20);
	}
}
#endif