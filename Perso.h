#pragma once
#include <string>

#ifndef Perso_DEF
#define PERSO_DEF

class Perso
{
private:
	int hp, hp_max;
	bool dead = false;
protected:
	std::string name;
public:
	Perso();
	Perso(std::string name, int hp);
	std::string getName();
	std::string print();
	int getHp();
	int getHpMax();
	bool isDead();

	void heal(int);
	void attack(Perso&);
	void attack(Perso&, int);
	void getDamage(int);
	void death();
};

#endif // !Perso_DEF