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
	void createTeam();
	void addExpToCharacter();
	void chooseTeam();
	void napierdalando(Character& c1, Character& c2);

private:
	int choice;
	bool playing;
	int curTeam = 0;
	std::vector< std::vector<Character> > teams;
	std::vector<std::string> teamsNames;

	//Functions
	int drawCharMenu()const;
	int drawTeamMenu()const;
};