#include "Game.h"

int main()
{
	Game game;
	game.createCharacter();
	std::cout << std::endl;

	while (game.getPlaying())
	{
		game.mainMenu();
	}
	return 0;
}