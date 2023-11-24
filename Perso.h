#pragma once
#include <string>
#include <vector>

class Weapon;
class Effect;

class Perso
{
private:
	int hp, hp_max;
	bool dead = false;
protected:
	std::string name;
	Weapon* weapon;
	std::vector<Effect*> effect;
public:
	Perso();
	Perso(std::string name, int hp, Weapon*);
	std::string getName();
	std::string print();
	int getHp();
	int getHpMax();
	std::vector<Effect*>* getEffect();
	bool isDead();

	void heal(int);
	void attack(Perso&);
	void takeAttack(Weapon*);
	void getDamage(int);
	void death();

	void putEffect(Effect*);

};

