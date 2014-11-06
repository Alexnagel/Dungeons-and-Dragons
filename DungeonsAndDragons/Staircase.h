#pragma once
#include "Room.h"
#include "StairCaseDirection.h"

class Staircase : public Room
{
private: 
	StairCaseDirection direction;

public:
	Staircase(int level, StairCaseDirection direction);
	virtual ~Staircase();

	std::string RoomCharacter();
	std::string Print() override;
};

