#include "Game.h"
#include<limits>

Game::Game()
{
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
	int choice;
	do
	{
		choice = _getch();
		choice -= '0';
	} while (choice < 1 || choice > 7);
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
		teams[curTeam].addExpToCharacter();
		break;
	case 5:
	{
		teams[curTeam].charactersMenu();
		break;
	}
	case 6:
		teams[curTeam].createCharacter();
		break;
	case 7:
		napierdalando(teams[curTeam][0], teams[curTeam][1]);
			break;
	default:
		break;
	}
}

void Game::createTeam()
{
	system("cls");
	std::cout << "Podaj nazwe teamu: ";
	std::string name = "NONE";
	std::cin >> name;
	//creating new team
	teams.emplace_back(Team(name));
	//init hero name
	curTeam = teams.size() - 1;
	system("cls");
}




void Game::chooseTeam()
{
	this->curTeam = drawTeamMenu();
	system("cls");
}

void Game::napierdalando(Character & c1, Character & c2)
{
	/*
	c1.useSpell(SC.getFireball(), c2);
	c1.useSpell(SC.getFireball(), c2);
	c1.useSpell(SC.getLHeal(), c2);
	SC.useSpell(c1, c2, SPELLS::LesserHeal);
	*/
}

void Game::battle(Team& t1, Team& t2)
{
	std::cout << "Ten, napieprzaja sie dwie druzyny!";
	std::cin.get();
	system("cls");
	int teamIndex =0;
	int cap1 = (int)t1.size();
	int cap2 = (int)t2.size();
	int wholeCap = cap2 + cap1;
	std::vector<bool> atackers(wholeCap, 0);
	int index;
	while (wholeCap-- > 0 && t1.areAlive() && t2.areAlive())
	{
		do
		{
			index = rand() % wholeCap;
		} while (atackers[index] == true);
		if (index < cap1)
		{

		}
		else
		{
			index -= cap1;
		}
	}
	
	//
}





int Game::drawTeamMenu() const
{
	const size_t size = teams.size();
	char choice;
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". " << teams[curTeam].getName() << "\n";
	}
	std::cout << "Wybierz team: ";
	do
	{
		choice = _getch();
		choice -= '0';
	} while (--choice < 0 || choice >= size);
	return choice;
}




