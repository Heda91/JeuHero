#pragma once
#include "Perso.h"

class Weapon
{
private:
	int damage;
public:
	Weapon(int damage);
	void attack(Perso&);
};
