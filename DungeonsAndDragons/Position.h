#pragma once

class Position
{
private:
	int x;
	int y;

public:
	// Constructor
	Position(int x, int y);
	virtual ~Position();

	// Functions
	int GetX();
	int GetY();
};

