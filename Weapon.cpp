#pragma once
#include "Weapon.h"

Weapon::Weapon(int damage, char typeATK, int defP, int defM, int defF, int defN){
	this->damage = damage;
	this->typeATK = typeATK;
	this->defP = defP;
	this->defM = defM;
	this->defF = defF;
	this->defN = defN;
}
char Weapon::getTypeATK() { return typeATK; }
int Weapon::getDefP() { return defP; }
int Weapon::getDefM() { return defM; }
int Weapon::getDefF() { return defF; }
int Weapon::getDefN() { return defN; }
int Weapon::getDamage() { return damage; }

void Weapon::attack(Perso* p, int tank) { p->getDamage(this->damage-tank); }


