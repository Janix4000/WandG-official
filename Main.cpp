#include "Game.h"

int main()
{
	Game game;
	

	while (game.getPlaying())
	{
		game.mainMenu();
	}
	return 0;
}