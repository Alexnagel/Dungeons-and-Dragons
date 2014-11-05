#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon() : attack(1)
{
}


Weapon::~Weapon()
{
}

// Functions
void Weapon::Equiped(bool p_equiped)
{
	equiped = p_equiped;
}

bool Weapon::IsEquiped()
{
	return equiped;
}

int Weapon::GetAttack()
{
	return attack;
}
