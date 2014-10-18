#include "stdafx.h"
#include "Position.h"

Position::Position(int x, int y) : x(x), y(y)
{
}

Position::~Position()
{
}

int Position::GetX()
{
	return x;
}

int Position::GetY()
{
	return y;
}
