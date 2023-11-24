#pragma once
#include "Game.h"
#include "Effect.h"
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int random(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
unsigned int Game::getTurn() { return this->turn; }

Game::Game(Perso p, Perso e[3]) {
	this->player = p;
	this->ennemy[0] = e[0];
	this->ennemy[1] = e[1];
	this->ennemy[2] = e[2];
	
}

void Game::game() {
	Burn ko(&player, "brulure", 2);
	Burn kn(&ennemy[2], "brulure in game", 2);
	while (!player.isDead() && (!ennemy[0].isDead() || !ennemy[1].isDead() || !ennemy[2].isDead())) {
		this->turn += 1;
		this->turnPlayer();
		this->turnBot();

		this->effectEndTurn(&this->player);
		this->effectEndTurn(&this->ennemy[0]);
		this->effectEndTurn(&this->ennemy[1]);
		this->effectEndTurn(&this->ennemy[2]);

		cout << this->player.print() << endl;
	}
	cout << endl << "FIN DU JEU (en " << this->getTurn() << " tours)";
}
void Game::turnPlayer() {
	int action;
	cout << endl << "0 = attaquer | 1 = soigner" << endl;
	cout << "Choisie une action: ";
	cin >> action;
	switch (action){
	case 0:
		cout << ennemy[0].print() << endl << ennemy[1].print() << endl << ennemy[2].print() << endl;
		while (action < 1 || action>3) {
			cout << "Qui veux tu attquer ?: 1/2/3 ";
			cin >> action;
			if (ennemy[action - 1].isDead()) { 
				action = 0;
				cout << "L'ennemi vise est deja a terre aies un peu de respect" << endl;
			}
		}
		player.attack(ennemy[action - 1]);
		break;
	case 1:
		player.heal(2);
		cout << "Tu te soignes de 2 pv" << endl;
		cout << player.print() << endl;
		break;
	default:
		cout << "Commande innexistante" << endl;
		turnPlayer();
		break;
	}
}
void Game::turnBot() {
	for (int i = 0; i < 3; i++) {
		if (!ennemy[i].isDead()) {
			if (ennemy[i].getHp() != ennemy[i].getHpMax() && random(0, 100) <= 20) {
				ennemy[i].heal(random(2,4));
				cout << ennemy[i].getName() << "s'est soigne" << endl;
			}
			else { ennemy[i].attack(this->player); }
		}
	}
}
void Game::effectEndTurn(Perso* p) {
	if (!p->isDead()){
		vector<Effect*>* eff = p->getEffect();
		for (int i = 0; i < eff->size(); i++) {
			bool end = eff->at(i)->advanceTurn();
			if (end) { eff->erase(eff->begin() + i); }
		}
	}
}

