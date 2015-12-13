#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class GameObject
{
protected:
	GameObject(const string& = "");
public:
	virtual ~GameObject();

	string getName();
	static int getCount();

private:
	const string kName;
	static int count;
};

#endif // !GAME_OBJECT