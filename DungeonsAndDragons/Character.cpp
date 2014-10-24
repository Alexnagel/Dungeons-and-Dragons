#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

// Getters
std::string Character::GetName()
{
	return name;
}

int Character::GetLevel()
{
	return level;
}

int Character::GetHp()
{
	return hp;
}