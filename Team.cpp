#include "Team.h"



Team::Team(const std::string& name)
	:
	name(name)
{
	createCharacter();
}


Team::~Team()
{
}

bool Team::areAlive() const
{
	for (const auto &c : characters)
	{
		if (c.isAlive()) return true;
	}
	return false;
}

void Team::createCharacter()
{
	std::cout << "Podaj imie bohatera: ";
	std::string name = "NONE";
	std::cin >> name;
	//creating new hero in team
	characters.emplace_back(Character(name));
	system("cls");
}

int Team::drawCharMenu() const
{
	system("cls");
	const size_t size = characters.size();
	char choice;	
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << "." << std::setw(10) << characters[i].getName();
			if (!characters[i].isAlive()) std::cout << "[Dead] "; 
			std::cout << "\n";
		}
		std::cout << "Wybierz postac: ";
		do
		{
			choice = _getch();
			choice -='0';
		} while (--choice < 0 || choice >= size);
	
	return int(choice);
}

void Team::charactersMenu()
{
	system("cls");
	std::cout << "-----Menu bohaterow-----" << "\n\n";
	int choice;
	choice = drawCharMenu();
	system("cls");
	characters[choice].drawSheet();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "ENTER TO MENU";
	std::cin.get();
	system("cls");

}

void Team::addExpToCharacter()
{
	system("cls");
	int exp;
	int choice = drawCharMenu();
	std::cout << std::endl;
	std::cout << "Dodaj do wybranej postaci exp: ";
	std::cin >> exp;
	characters[choice].addExp(exp);
	system("cls");
}