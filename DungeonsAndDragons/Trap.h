#pragma once
#include "Utils.h"

class Trap
{
private:
	std::string description;
	int damage;

public:
	Trap();
	Trap(int level);
	virtual ~Trap();

	std::string GetDescription();
	int GetDamage();
};

