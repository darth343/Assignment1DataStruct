#ifndef OUTFIT_H
#define OUTFIT_H
#include "Item.h"

class Outfit :	public Item
{
private:
	const int kSPECIAL;
public:
	Outfit(const string& name, const int& durab, const int& kSPECIAL);
	~Outfit();
	const int getSPECIAL();
	virtual void receiveDamage(const int & damage);
};

#endif