#ifndef DWELLER_H
#define DWELLER_H
#include "GameObject.h"
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"
class Dweller :	public GameObject
{
public:
	Dweller(const string& name, const int& SPECIAL);
	~Dweller();
	
	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();
	void setPosition(const Vec2D& pos);
	const Vec2D getPosition();
	void receiveHealthDamage(const int& damage);
	void receiveRadDamage(const int& radDmg);
	void receiveEquipmentDamage(const int& damage);
	void addStimpak(const int& stims);
	void addRadAway(const int& RadAways);
	void useStimpak();
	void useRadAway();
	Outfit* getOutfit();
	Weapon* getWeapon();
	Outfit* assignOutfit(Outfit * of);
	Weapon* assignWeapon(Weapon* wp);
	bool isDead();
	const int getMaxHealth();
	const int calculateSPECIAL();
	void set_SPECIAL();
	

private:
	Vec2D position_;
	int SPECIAL_;
	const int conSPECIAL_;
	int health_;
	int maxHealth_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;
};

#endif // !DWELLER_H