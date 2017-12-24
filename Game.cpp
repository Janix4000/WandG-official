#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
	createTeam();


}

Game::~Game()
{
}

void Game::mainMenu()
{
	std::cout << " = MENU = " << std::endl
		<< std::endl
		<< "1. Wyjdz" << std::endl
		<< "2. Stworz Team" << std::endl
		<< "3. Wybierz Team" << std::endl
		<< "4. Stworz Postac" << std::endl
		<< "5. Level Up" << std::endl
		<< "6. Staty" << std::endl
		<< std::endl
		<< "Wybierz: ";
	std::cin >> choice;
	std::cin.ignore();
	switch (choice)
	{
	case 1:
		playing = false;
		break;
	case 2:
		createTeam();
		break;
	case 3:
		chooseTeam();
		break;
	case 4:
		createCharacter();
		break;
	case 5:
		addExpToCharacter();
		break;
	case 6:
		for (const Character& hero : teams[curTeam])
		{
			hero.drawSheet();
			std::cout << std::endl;
		}
		break;
	default:
		break;
	}
}

void Game::createTeam()
{
	std::cout << "Podaj nazwe Teamu: ";
	std::string name = "NONE";
	std::cin >> name;
	std::cin.ignore();
	teamNames.emplace_back(name);
	teams.emplace_back();
	curTeam = teams.size() - 1;
	createCharacter();
}

void Game::addExpToCharacter()
{
	int exp;
	std::cout << std::endl;
	std::cout << "Dodaj wszystkim postacia exp: ";
	std::cin >> exp;
	for (Character& hero : teams[curTeam])
	{
		hero.addExp(exp);
	}
}

void Game::chooseTeam()
{
	std::cout << std::endl;
	int cap = teams.size();
	for (int i = 0; i < cap; i++)
	{
		std::cout << i + 1 << ". " << teamNames[i] << std::endl;
	}
	std::cout << std::endl
		<< "Wybierz: ";
	choice=0;
	std::cin >> choice;
	choice--;
	if (choice < 0) choice = 0;
	else if (choice >= cap) choice = cap - 1;
	curTeam = choice;
}

void Game::createCharacter()
{
	std::cout << "Podaj imie bohatyra: ";
	std::string name = "NONE";
	std::cin >> name;
	std::cin.ignore();
	teams[curTeam].emplace_back(Character(name));
	//teams[curTeam][teams[curTeam].size() - 1].init();
}

