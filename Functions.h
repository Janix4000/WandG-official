#pragma once
#include <iostream>
#include <limits>

namespace out
{
	void writePressEnter()
	{
		std::cout << "WCISNIJ ENTER...";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>().max(), '\n');
		char input;
		do
		{
			input = std::cin.get();
		}
		while (input != '13');
		system("cls");
	}
}