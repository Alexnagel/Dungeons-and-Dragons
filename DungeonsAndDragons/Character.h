#pragma once
class Character
{
public:
	Character();
	virtual ~Character();

	// Functions
	std::string GetName();
	int GetLevel();
	int GetHp();

protected:
	std::string name;
	int hp;
	int level;
};

