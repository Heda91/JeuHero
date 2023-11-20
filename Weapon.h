#pragma once
#include "Perso.h"

class Weapon
{
private:
	int damage;
	char typeATK; //peut etre 'P'hysique, 'M'agique, 'F'eu, 'N'ature.
	int defP, defM, defF, defN;
public:
	Weapon(int damage, char typeATK, int defP = 0, int defM = 0, int defF = 0, int defN = 0);
	char getTypeATK();
	int getDefP();
	int getDefM();
	int getDefF();
	int getDefN();
	int getDamage();

	void attack(Perso&, int tank = 0);
};
