#pragma once
#include <algorithm>
#include <memory>
#include <math.h>
#include "Team.h"

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
	
	void chooseTeam();
	void napierdalando(Character& c1, Character& c2);
	void battleSimulator(Character& Hero);
	void battle(Team& t1, Team& t2);

private:
	bool playing;
	size_t curTeam = 0;
	std::vector< Team > teams;
	
	std::vector<std::unique_ptr<Monster>> monsters;

	int drawTeamMenu()const;
	void insertGoblin(const std::string& name = "Maciej");
};