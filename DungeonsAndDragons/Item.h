#pragma once
#include <random>

class Item
{
private:
	std::string name;

protected:
	int seed;
	std::mt19937 rng;
	int RandomNumber(int max);
	int RandomNumber(int min, int max);

public:
	Item();
	virtual ~Item();

	// Functions
	std::string GetName();
};

