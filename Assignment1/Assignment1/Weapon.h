#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
class Weapon :	public Item
{
private:
	const int kAttackDmg;
public:
	Weapon(const string& name, const int& durab, const int& dmg);
	~Weapon();
	const int getAttackDmg();
	virtual void receiveDamage(const int & damage);
};

#endif // !WEAPON_H