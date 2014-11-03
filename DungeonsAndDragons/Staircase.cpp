#include "stdafx.h"
#include "Staircase.h"


Staircase::Staircase(int level, StairCaseDirection direction)
	:Room(level)
{
	this->direction = direction;
}

std::string Staircase::RoomCharacter()
{
	switch (direction)	
	{
	case StairCaseDirection::UP: return "U"; break;
	case StairCaseDirection::DOWN: return "D"; break;
	default:
		return ".";
		break;
	}
}

Staircase::~Staircase()
{
}
