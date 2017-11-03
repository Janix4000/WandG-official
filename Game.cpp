#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
}

Game::~Game()
{
}

void Game::mainMenu()
{
	std::cout << " = MENU = " << std::endl
		<< std::endl
		<< "1. Wyjdz" << std::endl
		<< "2. Podroz " << std::endl
		<< "3. Sklep" << std::endl
		<< "4. Level Up" << std::endl
		<< "5. Staty" << std::endl
		<< std::endl
		<< "Wybierz: ";
	std::cin.ignore();
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		playing = false;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		character.drawSheet();
		break;
	default:
		break;
	}
}

void Game::createCharacter()
{
	std::cout << "Podaj imie bohatera: ";
	std::string name;
	std::cin >> name;
	character.init(name);
}

