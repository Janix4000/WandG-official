#pragma once
#include <string>
#include <iostream>
#include "Dice.h"
#include <vector>


enum class SPELLS
{
	Fireball = 0,
	LesserHeal
};

class SpellCodex
{
public:
	class Spell
	{
	protected:
		std::string name;
		int manaCost;
		int paCost;
		int minIntell;
	public:
		Spell(std::string name = "NONE", int mCost = 0, int paCost = 0, int minI = 0)
			:
			name(name),
			manaCost(mCost),
			minIntell(minI)
		{}

		inline const std::string& getName()const { return name; }
		inline int getMCost()const { return manaCost; }
		inline int getPACost()const { return paCost; }
		inline int getMinI()const { return minIntell; }

		template<typename C, typename T>
		void operator()(C& caster, T& target) { ; }

	protected:
		template<typename C>
		bool Cast(C& caster) const
		{
			system("cls");
			if (caster.getIntelligence() < minIntell)
			{
				std::cout << caster.getName()
					<< " ma za malo inteligencji by rzucic to zaklecie! \n";
				return 0;
			}
			else if (caster.getMana() < manaCost)
			{
				std::cout << caster.getName()
					<< " ma za malo many by  rzucic to zaklecie! \n";
				return 0;
			}
			else if (caster.getPA() < paCost)
			{
				std::cout << caster.getName()
					<< " nie ma wystarczajaco punktow akcji by rzucic to zaklecie! \n";
				return 0;
			}
			return 1;
		}
	};
private:
	

	class Fireball
		:
		public Spell
	{
	private:
		int damage = 10;
	public:
		Fireball()
			:
			Spell("Fireball", 7, 3, 5)
		{}

		//Cast
		template<typename C, typename T>
		void operator()(C& caster, T& target) 
		{
			if (!Spell::Cast(caster)) return;
			int finalDam = caster.getIntelligence() + damage + D6();
			target.takeDamage(finalDam);
			caster.addMana(-manaCost);
			caster.addPA(-paCost);
			std::cout << caster.getName() << " zajebal " << target.getName() << " za " << finalDam << " punktow!\n";
			std::cin.get();
			system("cls");
		}
	};
	class LesserHeal
		:
		public Spell
	{
	private:
		int heal = 22;
	public:
		LesserHeal()
			:
			Spell("Lesser Heal", 6, 2, 7)
		{}

		template<typename C, typename T>
		void operator()(C& caster, T& target) const
		{
			if (!Spell::Cast(caster)) return;
			int finalHeal = -(int((float)caster.getIntelligence()*1.5f)
				+ heal + D6());
			target.takeDamage(finalHeal);
			caster.addMana(-manaCost);
			caster.addPA(-paCost);
			std::cout << caster.getName() << " uleczyl " << target.getName() << " o " << -finalHeal << " punktow.\n";
			std::cin.get();
			system("cls");
		}
	};
	
private:
	Fireball fireball;
	LesserHeal lHeal;

public:
	const Fireball& getFireball() const
	{
		return fireball;
	}
	const LesserHeal& getLHeal() const
	{
		return lHeal;
	}

	template<typename C, typename T>
	bool useSpell(C caster, T target, int index)
	{
		switch (index)
		{
		case int(SPELLS::Fireball):
			fireball(caster, target);
			break;
		case int(SPELLS::LesserHeal) :
			lHeal(caster, target);
			break;
		default:
			return false;
			break;
		}
		return true;
	}

	template<typename C, typename T>
	bool useSpell(C caster, T target, SPELLS index)
	{
		return useSpell(caster, target, int(index));
	}
};

