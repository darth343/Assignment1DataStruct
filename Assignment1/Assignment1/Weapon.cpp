#include "Weapon.h"


Weapon::Weapon(const string& name, const int& durab, const int& dmg) : Item(name, durab), kAttackDmg(dmg)
{
}


Weapon::~Weapon()
{
}

void Weapon::receiveDamage(const int & damage)
{
	this->durability_ -= damage;
}

const int Weapon::getAttackDmg()
{
	if (durability_ < 1)
		return 1;
	return this->kAttackDmg;
}