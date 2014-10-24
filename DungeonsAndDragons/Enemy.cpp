#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
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


int Enemy::Attack()
{
	// Gebruik een random getal, of de enemy mist of niet?
	if (50 < 80) // <-- onzin getallen atm...
	{
		// De enemy raakt de tegenstander
		// Bereken het aantal damage dat de tegenstander doet op basis van het level en een random.
		int damage = 0;
		return damage;
	}
	else
	{
		return 0;// The enemy missed
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