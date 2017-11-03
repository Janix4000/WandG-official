#include "Game.h"

int main()
{
	Game game;
	game.createCharacter();
	while (game.getPlaying())
	{
		game.mainMenu();
	}
	return 0;
}