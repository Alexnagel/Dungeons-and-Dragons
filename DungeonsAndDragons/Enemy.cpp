#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy(int floor)
{
	// Add a name
	switch (RandomNumber(7))
	{
	case 0: name = "Necromancer"; break;
	case 1: name = "Skeleton"; break;
	case 2: name = "Rat"; break;
	case 3: name = "Zombie"; break;
	case 4: name = "Cyclops"; break;
	case 5: name = "Vampire"; break;
	case 6: name = "Giant Bat"; break;
	case 7: name = "Gargoyle"; break;
	}

	// Add a lvl
	switch (floor)
	{
	case 0: level = RandomNumber(1,3); break;
	case 1: level = RandomNumber(2, 4); break;
	case 2: level = RandomNumber(3, 4); break;
	case 3: level = RandomNumber(3, 5); break;
	case 4: level = RandomNumber(3, 6); break;
	case 5: level = RandomNumber(4, 6); break;
	case 6: level = RandomNumber(4, 7); break;
	case 7: level = RandomNumber(5, 8); break;
	case 8: level = RandomNumber(6, 9); break;
	case 9: level = RandomNumber(8, 10); break;
	}

	// Add hp
	switch (level)
	{
	case 1: hp = 50; maxHp = 50; break;
	case 2: hp = 60; maxHp = 60; break;
	case 3: hp = 70; maxHp = 70; break;
	case 4: hp = 70; maxHp = 70; break;
	case 5: hp = 80; maxHp = 80; break;
	case 6: hp = 85; maxHp = 85; break;
	case 7: hp = 90; maxHp = 90; break;
	case 8: hp = 100; maxHp = 100; break;
	case 9: hp = 110; maxHp = 110; break;
	case 10: hp = 120; maxHp = 120; break;
	}
	
	// Add a xp amount
	switch (level)
	{
	case 1: xp = 50; break;
	case 2: xp = 60; break;
	case 3: xp = 75; break;
	case 4: xp = 90; break;
	case 5: xp = 110; break;
	case 6: xp = 135; break;
	case 7: xp = 170; break;
	case 8: xp = 210; break;
	case 9: xp = 270; break;
	case 10: xp = 400; break;
	}
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

// De onderstaande link zou mss leuk zijn voor het damage systeem.
// http://gamedev.stackexchange.com/questions/45901/ideas-for-attack-damage-algorithm-language-irrelevant
int Enemy::Attack()
{
	int result = RandomNumber(100);
	if (result < 80)
	{
		// De enemy raakt de tegenstander
		// Bereken het aantal damage dat de tegenstander doet op basis van het level en een random.
		int damage = (RandomNumber(1, 4) * level) / 3;
		return damage;
		//return 50;
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