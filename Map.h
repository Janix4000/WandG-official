#pragma once
#include "Monster.h"
#include <memory>
#include <algorithm>

class Map
{
private:
	class Place
	{
		std::vector<Place*> paths;
		std::vector<std::unique_ptr<Monster>> monsters;
		std::vector<Character*> charactersIn;

		std::unique_ptr<Item> treasure;

		std::string name;

		bool closed;

	public:
		bool isConectedTo(const Place& target) const;
		void connectTo(Place& target);

	};


	std::vector<Place> places;



	void connectPlaces(Place& first, Place& second);

	void showPaths(Character& target);
	void translateCharTo(Character& target, Place& destination);

};