#pragma once
#include <algorithm>
#include <math.h>
#include "Character.h"

class Game
{
public:
	Game();
	~Game();

	//Operators

	//Functions
	void mainMenu();
	inline bool getPlaying() const { return playing; }
	void createCharacter();

private:
	int choice;
	bool playing;
	Character character;
};