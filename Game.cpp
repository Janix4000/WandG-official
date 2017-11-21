#include "Game.h"
#include<limits>

Game::Game()
{
	choice = 0;
	playing = true;
	createTeam();
	/*
	Inventory inv;
	inv.addItem(Weapon("Stasiek"));
	inv.addItem(Weapon("Mariola"));
	inv.addItem(Weapon("Andrzej"));
	inv.addItem(Armor("Husiek"));
	for (int i = 0; i < inv.size(); i++)
	{
		std::cout << inv[i].getName() << std::endl;
	}
	*/
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
		<< "4. Level Up" << std::endl
		<< "5. Staty" << std::endl
		<< "6. Stworz bohatera" << std::endl
		<< "7. Nap" << std::endl
		<< std::endl
		<< "Wybierz: ";
	std::cin >> choice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
		addExpToCharacter();
		break;
	case 5:
	{
		for (int i = 0; i < teams[curTeam].size(); i++)
		{
			teams[curTeam][i].drawSheet();
			std::cout << "\n";
		}
		break;
	}
	case 6:
		createCharacter();
		break;
	case 7:
		napierdalando(teams[curTeam][0], teams[curTeam][1]);
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
	//creating new hero in team
	teams[curTeam].emplace_back(Character(name));
}

void Game::createTeam()
{
	system("cls");
	std::cout << "Podaj nazwe teamu: ";
	std::string name = "NONE";
	std::cin >> name;
	//creating new team
	teams.emplace_back();
	//init hero name
	teamsNames.emplace_back(name);
	curTeam = teams.size() - 1;
	createCharacter();
}


void Game::addExpToCharacter()
{
	system("cls");
	int exp;
	int choice = drawCharMenu();
	std::cout << std::endl;
	std::cout << "Dodaj do wybranej postaci exp: ";
	std::cin >> exp;
	teams[curTeam][choice].addExp(exp);
}

void Game::chooseTeam()
{
	system("cls");
	this->curTeam = drawTeamMenu();
	system("cls");
}

void Game::napierdalando(Character & c1, Character & c2)
{
	c1.useSpell(sc::Fireball(), c2);
}

int Game::drawCharMenu() const
{
	system("cls");
	const int size = teams[curTeam].size();
	int choose;
	std::cout<<"Wybierz postac: \n";
	while (true)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << ". " << teams[curTeam][i].getName() << "\n";
		}
		std::cin >> choose;
		if (--choose < 0 || choose >= size || std::cin.fail())
		{
			std::cout << "Pojebalo? Wpisz normalna liczbe\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	}
	return choose;
}

int Game::drawTeamMenu() const
{
	const int size = teams.size();
	int choose;
	std::cout << "Wybierz team: ";
	while (true)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << ". " << teamsNames[i] << "\n";
		}
		std::cin >> choose;
		if (--choose < 0 || choose >= size || std::cin.fail())
		{
			std::cout << "Wpisz normalna liczbe\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	}
	return choose;
}

