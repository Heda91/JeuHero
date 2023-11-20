#pragma once
#include "Perso.h"

#ifndef Weapon_DEF
#define WEAPON_DEF

class Weapon
{
private:
	int damage;
public:
	Weapon(int damage);
	void attack(Perso&);
};
#endif // !Weapon_DEF
