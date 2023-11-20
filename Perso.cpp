#pragma once
#include "Perso.h"
#include "Weapon.h"
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
string Perso::getName() { return this->name; }
string Perso::print() {
	string txt = "Joueur: " + this->getName() + " | ";
	txt += "Vie: " + to_string(this->hp) + "/" + to_string(this->hp_max) + " | ";
	txt += "Mort: " + to_string(this->dead);
	return txt;
}
int Perso::getHp() { return this->hp; }
int Perso::getHpMax() { return this->hp_max; }
bool Perso::isDead() { return dead; }

void Perso::heal(int hp) {
	if (hp + this->hp > this->hp_max) { this->hp = hp_max; }
	else { this->hp += hp; }
}
void Perso::attack(Perso& p) {
	cout << this->name << " a attaque " << p.getName() << endl;
	this->weapon->attack(p);
}
void Perso::getDamage(int damage) {
	this->hp -= damage;
	if (hp > 0) {
		cout << this->name << " a subit " << damage << " degats!" << endl;
	}
	else { this->death(); }
}
void Perso::death() { 
	this->dead = true;
	this->hp = 0;
	cout << this->name << " est mort." << endl;
}



