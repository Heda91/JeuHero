#include "Effect.h"
#include <string>

//Effect

Effect::Effect(std::string name, int turn) {
	this->name = name;
	this->turn = turn;
}
std::string Effect::getName() { return this->name; }
int Effect::getTurn() { return this->turn; }
void Effect::setTurn(int turn) { this->turn = turn; }
bool Effect::advanceTurn(Perso& p) {
	this->playEndTurn(p);
	this->turn -= 1;
	if (this->turn <= 0) { return true; }
	else { return false; }
}
void Effect::play(Perso& p) { return; }
void Effect::playEndTurn(Perso& p) { return; }
//Brulure

Burn::Burn(std::string name, int turn, int damage) : Effect(name, turn) { this->damage = damage; }
void Burn::play(Perso& p) {
	p.death();
}
