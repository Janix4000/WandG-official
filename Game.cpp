#include "Game.h"

Game::Game()
{
	choice = 0;
	playing = true;
	createCharacter();

	Inventory inv;
	inv.addItem(Weapon("Stasiek"));
	inv.addItem(Weapon("Mariola"));
	inv.addItem(Weapon("Andrzej"));
	inv.addItem(Armor("Husiek"));
	for (int i = 0; i < inv.size(); i++)
	{
		std::cout << inv[i].getName() << std::endl;
	}

}

Game::~Game()
{
}

void Game::mainMenu()
{
	std::cout << " = MENU = " << std::endl
		<< std::endl
		<< "1. Wyjdz" << std::endl
		<< "2. Stworz Bohatera" << std::endl
		<< "3. Wybierz Bohatera" << std::endl
		<< "4. Level Up" << std::endl
		<< "5. Staty" << std::endl
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
		createCharacter();
		break;
	case 3:
		chooseCharacter();
		break;
	case 4:
		addExpToCharacter();
		break;
	case 5:
		characters[curCharacter].drawSheet();
		break;
	default:
		break;
	}
}

void Game::createCharacter()
{
	std::cout << "Podaj imie bohatera: ";
	std::string name = "NONE";
	std::cin >> name;
	characters.emplace_back(Character());
	curCharacter = characters.size() - 1;
	characters[curCharacter].init(name);
}

void Game::addExpToCharacter()
{
	int exp;
	std::cout << std::endl;
	std::cout << "Dodaj do aktualnej postaci exp: ";
	std::cin >> exp;
	characters[curCharacter].addExp(exp);
}

void Game::chooseCharacter()
{
	std::cout << std::endl;
	int cap = characters.size();
	for (int i = 0; i < cap; i++)
	{
		std::cout << i + 1 << ". " << characters[i].getName() << std::endl;
	}
	std::cout << std::endl
		<< "Wybierz: ";
	choice=0;
	std::cin >> choice;
	choice--;
	if (choice < 0) choice = 0;
	else if (choice >= cap) choice = cap - 1;
	curCharacter = choice;
}

