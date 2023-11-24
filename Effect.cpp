#include "Effect.h"
#include <string>
#include <iostream>

using namespace std;
//Effect

Effect::Effect(Perso* p, string name, int turn) {
	this->perso = p;
	this->name = name;
	this->turn = turn;
	p->putEffect(this);
}
string Effect::getName() { return this->name; }
int Effect::getTurn() { return this->turn; }
void Effect::setTurn(int turn) { this->turn = turn; }
bool Effect::advanceTurn() {
	this->playEndTurn();
	this->turn -= 1;
	if (this->turn <= 0) { return true; }
	else { return false; }
}
void Effect::play() { return; }
void Effect::playEndTurn() { return; }

//Brulure

Burn::Burn(Perso* p, string name, int turn, int damage) : Effect(p, name, turn) { this->damage = damage; }
void Burn::playEndTurn() { 
	cout << this->perso->getName() << " est en feu" << endl;
	this->perso->getDamage(this->damage);
}
