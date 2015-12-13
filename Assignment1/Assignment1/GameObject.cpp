#include "GameObject.h"

int GameObject::count = 0;

GameObject::GameObject(const string& name) : kName(name)
{
	count++;
}


GameObject::~GameObject()
{
	count--;
}

int GameObject::getCount()
{
	return count;
}

string GameObject::getName()
{
	return this->kName;
}