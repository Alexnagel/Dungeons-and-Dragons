#pragma once
#include "Item.h"
class Weapon :
	public Item
{
private:
	bool equiped;
	int attack;

protected:
	void GenerateItem(int itemNumber, int itemLevel);

public:
	Weapon();
	Weapon(int floor);
	Weapon(int itemNumber, int itemLevel);
	virtual ~Weapon();

	// Functions
	void Equiped(bool p_equiped);
	bool IsEquiped();
	int GetAttack();
};

