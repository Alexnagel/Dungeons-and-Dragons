#include "stdafx.h"
#include "Trap.h"


Trap::Trap()
{
}

Trap::Trap(int floor)
{
	int trapType = Utils::RandomNumber(1,5);
	switch (trapType)
	{
	case 1: description = "You walked in a bear trap, your leg is busted"; break;
	case 2: description = "You fell into a hole in the ground, you've hit the ground hard"; break;
	case 3: description = "A big cage fell around you, you struggle to get out of it"; break;
	case 4: description = "A wild dwarf appeared! He's attacked you and your ankle is hurting"; break;
	case 5: description = "You missed a rat in the corner and it attacked you"; break;
	}

	// set base damage
	damage = 2;
	damage *= (floor + 2);
}

std::string Trap::GetDescription()
{
	return description;
}

int Trap::GetDamage()
{
	return damage;
}


Trap::~Trap()
{
}
