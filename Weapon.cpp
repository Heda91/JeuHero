#pragma once
#include "Weapon.h"


Weapon::Weapon(int damage){
	this->damage = damage;
}

void Weapon::attack(Perso& p) { p.getDamage(this->damage); }

