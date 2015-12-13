#include "Item.h"


Item::Item(const string& name, const int& durab) : GameObject(name), durability_(durab)
{
}


Item::~Item()
{
}

const int Item::getDurability()
{
	return this->durability_;
}