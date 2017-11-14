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
	void createTeam();
	void addExpToCharacter();
	void chooseTeam();
	void createCharacter();

private:
	int choice;
	bool playing;
	int curTeam = 0;
	std::vector<std::vector<Character>> teams;
	std::vector<std::string> teamNames;
};