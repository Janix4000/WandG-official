#include "Game.h"


int main()
{
	srand((unsigned int)time(NULL));
	Game game;
	

	while (game.getPlaying())
	{
		game.mainMenu();
	}
	return 0;
}