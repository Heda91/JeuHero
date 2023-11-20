#pragma once
#include <string>

class Weapon;

class Perso
{
private:
	int hp, hp_max;
	bool dead = false;
protected:
	std::string name;
	Weapon* weapon;
public:
	Perso();
	Perso(std::string name, int hp, Weapon*);
	std::string getName();
	std::string print();
	int getHp();
	int getHpMax();
	bool isDead();

	void heal(int);
	void attack(Perso&);
	void getDamage(int);
	void death();
};

