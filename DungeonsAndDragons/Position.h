#pragma once

class Position
{
private:
	int x;
	int y;

public:
	// Constructor
	Position(int x, int y);
	~Position();

	// Functions
	int GetX();
	int GetY();
};

