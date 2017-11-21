#pragma once
#include <string>
#include <iostream>
#include "Dice.h"

namespace sc
{
	class Fireball
	{
	private:
		std::string name = "Fireball";
		int damage = 10;
		int manaCost = 5;
		int paCost = 3;
		int minIntell = 5;
	public:
		template<typename C, typename T>
		void operator()(&C, &T) const
		{
			system("cls");
			if (C.getIntelligence() < minIntell)
			{
				std::cout << C.getName() << " ma za malo inteligencji by rzucic to zaklecie! \n";
				return;
			}
			else if (C.getMana < manaCost)
			{
				std::cout << C.getName() << " ma za malo many by  rzucic to zaklecie! \n";
				return;
			}
			else if (C.getPA() < paCost)
			{
				std::cout << C.getName() << " nie ma wystarczajaco punktow akcji by rzucic to zaklecie! \n";
				return;
			}
			std::cout << C.getName() << " uzyl " << name <<" na " << T.getName() << "!\n";
			int finalDam = C.getIntelligence + damage + D6();
			T.takeDamage(finalDam);
			C.addMana(-manaCost);
			C.addPA(-paCost);
		}

	};
}
