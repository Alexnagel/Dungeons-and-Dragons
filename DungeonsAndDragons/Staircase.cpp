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

std::string Staircase::Print()
{
	std::string output = description + "\n";
	if (directions.empty())
		SetDirections();

	output.append(directions + "\n\n");

	switch (direction)
	{
	case StairCaseDirection::UP: 
		output.append("Options: Up\n");
		break;
	case StairCaseDirection::DOWN: 
		output.append("Options: Down\n");
		break;
	}

	return output;
}