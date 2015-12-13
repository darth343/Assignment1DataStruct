#include "Outfit.h"


Outfit::Outfit(const string& name, const int& durab, const int& SPECIAL) : Item(name, durab), kSPECIAL(SPECIAL)
{
}


Outfit::~Outfit()
{
}

void Outfit::receiveDamage(const int & damage)
{
	this->durability_ -= damage;
}

const int Outfit::getSPECIAL()
{
	if (durability_ < 1)
		return 0;
	else
		return this-> kSPECIAL;
}