#include "Dweller.h"


Dweller::Dweller(const string& name, const int& SPECIAL) : GameObject(name), SPECIAL_(SPECIAL), position_(0, 0), health_(100), radiation_(0), stimpak_(0), radaway_(0), outfit_(NULL), weapon_(NULL), conSPECIAL_(SPECIAL)
{
	maxHealth_ = 100 - radiation_;
}


Dweller::~Dweller()
{
}

const int Dweller::getSPECIAL()
{
	return this->SPECIAL_;
}

const int Dweller::getCurrentHealth()
{
	return this->health_;
}
const int Dweller::getCurrentRadDamage()
{
	return this->radiation_;
}
const int Dweller::getAttackDmg()
{
	if (weapon_ == NULL)
	{
		return 1;
	}
	else
	{
		return this->weapon_->getAttackDmg();
	}
}
void Dweller::setPosition(const Vec2D& pos)
{
	this->position_ = pos;
}

const Vec2D Dweller::getPosition()
{
	return this->position_;
}

void Dweller::receiveHealthDamage(const int& damage)
{
	this->health_ -= damage;
}

void Dweller::receiveRadDamage(const int& radDmg)
{

	this->radiation_ += radDmg;
	maxHealth_ = 100 - radiation_;
	if (health_ > maxHealth_)
		health_ = maxHealth_;

}

void Dweller::receiveEquipmentDamage(const int& damage)
{
	if (this->weapon_ != NULL)
		this->weapon_->receiveDamage(damage*0.5);
	if (this->outfit_ != NULL)
	{
		this->outfit_->receiveDamage(damage);
		if (this->outfit_->getDurability() < 1);
			SPECIAL_ = conSPECIAL_;
	}
}

void Dweller::addStimpak(const int& stims)
{
	this->stimpak_ += stims;
}

void Dweller::addRadAway(const int& RadAways)
{
	this->radaway_ += RadAways;
}

Outfit* Dweller::assignOutfit(Outfit * of)
{
	Outfit* suit = outfit_;
	if (outfit_ != NULL)
	{
		this->SPECIAL_ -= outfit_->getSPECIAL();
	}
	outfit_ = of;
	set_SPECIAL();
	return suit;
}

Weapon* Dweller::assignWeapon(Weapon* wp)
{
	Weapon* ptr = weapon_;
	weapon_ = wp;
	return ptr;
}

bool Dweller::isDead()
{
	if (this->health_ < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Outfit* Dweller::getOutfit()
{
	return this->outfit_;
}

Weapon* Dweller::getWeapon()
{
	return this->weapon_;
}

void Dweller::useStimpak()
{
	if (stimpak_ > 0)
	{
		health_ += 20;
		if (health_ > maxHealth_)
		{
			health_ = maxHealth_;
		}
		this->stimpak_--;
	}
}

void Dweller::useRadAway()
{
	if (radaway_ > 0)
	{
		radiation_ -= 10;
		maxHealth_ = 100 - radiation_;
		this->radaway_--;
	}
}

const int Dweller::getMaxHealth()
{
	return maxHealth_;
}

const int Dweller::calculateSPECIAL()
{
	int S, P, E, C, I, A, L;
	//Strength
	S = (this->SPECIAL_ / 1000000) + (outfit_->getSPECIAL() / 1000000);
	P = (this->SPECIAL_ / 100000 % 10) + (outfit_->getSPECIAL() / 100000 % 10);
	E = (this->SPECIAL_ / 10000 % 10) + (outfit_->getSPECIAL() / 10000 % 10);
	C = (this->SPECIAL_ / 1000 % 10) + (outfit_->getSPECIAL() / 1000 % 10);
	I = (this->SPECIAL_ / 100 % 10) + (outfit_->getSPECIAL() / 100 % 10);
	A = (this->SPECIAL_ / 10 % 10) + (outfit_->getSPECIAL() / 10 % 10);
	L = (this->SPECIAL_ % 10) + (outfit_->getSPECIAL() % 10);
	if (S > 9)
		S = 9;
	if (P > 9)
		P = 9;
	if (E > 9)
		E = 9;
	if (C > 9)
		C = 9;
	if (I > 9)
		I = 9;
	if (A > 9)
		A = 9;
	if (L > 9)
		L = 9;
	const int newSpecial = S * 1000000 + P * 100000 + E * 10000 + C * 1000 + I * 100 + A * 10 + L;
	return newSpecial;
}

void Dweller::set_SPECIAL()
{
	SPECIAL_ = calculateSPECIAL();
}