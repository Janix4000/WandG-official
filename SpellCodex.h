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
		void operator()(C& caster, T& target) const
		{
			system("cls");
			if (caster.getIntelligence() < minIntell)
			{
				std::cout << caster.getName() << " ma za malo inteligencji by rzucic to zaklecie! \n";
				return;
			}
			else if (caster.getMana() < manaCost)
			{
				std::cout << caster.getName() << " ma za malo many by  rzucic to zaklecie! \n";
				return;
			}
			else if (caster.getPA() < paCost)
			{
				std::cout << caster.getName() << " nie ma wystarczajaco punktow akcji by rzucic to zaklecie! \n";
				return;
			}
			std::cout << caster.getName() << " uzyl " << name <<" na " << target.getName() << "!\n";
			int finalDam = caster.getIntelligence() + damage + D6();
			target.takeDamage(finalDam);
			caster.addMana(-manaCost);
			caster.addPA(-paCost);
		}

	};
}
