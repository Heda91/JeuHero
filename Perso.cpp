#pragma once
#include "Perso.h"
#include "Weapon.h"
#include "Effect.h"
#include <iostream>
using namespace std;

Perso::Perso() {
	this->name = "NULL";
	this->hp = 0;
	this->hp_max = 0;
	this->dead = true;
}
Perso::Perso(string name,int hp, Weapon* w) {
	this->name = name;

	this->hp = hp;
	this->hp_max = hp;
	this->weapon = w;
}
string Perso::getName() { return '*' + this->name + '*'; }
string Perso::print() {
	string txt = "Nom: " + this->getName() + " | ";
	txt += "Vie: " + to_string(this->hp) + "/" + to_string(this->hp_max);
	txt += " | Mort: " + to_string(this->dead);
	if (effect.empty()) { txt += " | Pas d'effets"; }
	else {
		txt += " | Effets: ";
		for (int i = 0; i < this->effect.size(); i++) {
			txt += effect[i]->getName() + ", ";
		}
		txt.pop_back();
		txt.pop_back();
	}
	return txt;
}
int Perso::getHp() { return this->hp; }
int Perso::getHpMax() { return this->hp_max; }
vector<Effect*>* Perso::getEffect() { return &this->effect; }
bool Perso::isDead() { return dead; }

void Perso::heal(int hp) {
	if (hp + this->hp > this->hp_max) { this->hp = hp_max; }
	else { this->hp += hp; }
}
void Perso::attack(Perso& p) {
	cout << this->getName() << " a attaque " << p.getName() << endl;
	p.takeAttack(this->weapon);
}
void Perso::takeAttack(Weapon* w) {
	int tank = 0;
	switch (w->getTypeATK())
	{
	case 'P':
		tank = this->weapon->getDefP();
		break;
	case 'M':
		tank = this->weapon->getDefM();
		break;
	case 'F':
		tank = this->weapon->getDefF();
		break;
	case 'N':
		tank = this->weapon->getDefN();
		break;
	}
	if (w->getDamage() <= tank) { cout << "Attaque echoue" << endl; }
	else { w->attack(this, tank); }
}
void Perso::getDamage(int damage) {
	this->hp -= damage;
	if (hp > 0) {
		cout << this->getName() << " a subit " << damage << " degats!" << endl;
	}
	else { this->death(); }
}
void Perso::death() { 
	this->dead = true;
	this->hp = 0;
	cout << this->getName() << " est mort." << endl;
}

void Perso::putEffect(Effect* e) { this->effect.push_back(e); }

