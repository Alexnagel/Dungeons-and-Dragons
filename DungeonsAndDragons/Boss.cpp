#include "stdafx.h"
#include "Boss.h"


Boss::Boss()
{
	switch (RandomNumber(3))
	{
	case 0: name = "Ancient dragon"; break;
	case 1: name = "Black demon"; break;
	case 2: name = "Elder wizard"; break;
	case 3: name = "Giant ent"; break;
	}

	level = 12;
	maxHp = 1000;
	hp = maxHp;
}


Boss::~Boss()
{
}

// Functions
int Enemy::GetXp()
{
	if (hp == 0)
		return xp;
	else
		return 0;
}

// De onderstaande link zou mss leuk zijn voor het damage systeem.
// http://gamedev.stackexchange.com/questions/45901/ideas-for-attack-damage-algorithm-language-irrelevant
int Enemy::Attack()
{
	int result = RandomNumber(100);
	if (result < 80)
	{
		// De enemy raakt de tegenstander
		// Bereken het aantal damage dat de tegenstander doet op basis van het level en een random.
		int damage = (RandomNumber(1, 50) * level) / 3;
		return damage;
	}
	else
	{
		return 0;
	}
}

int Enemy::Hit(int damage)
{
	if (hp > damage)
		hp = hp - damage;
	else
		hp = 0;

	// Return the leftover hp of the enemy
	return hp;
}