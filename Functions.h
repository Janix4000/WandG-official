#pragma once
#include <iostream>
#include <limits>

namespace out
{
	inline void writePressEnter()
	{
		std::cout << "WCISNIJ ENTER...";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>().max(), '\n');
		std::cin.get();

		system("cls");
	}
}