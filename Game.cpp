#pragma once
#include "Game.h"
#include <iostream>
#include <vector>
using namespace std;

unsigned int Game::getTurn() { return this->turn; }

Game::Game(Perso p, Perso e[3]) {
	this->player = p;
	this->ennemy[0] = e[0];
	this->ennemy[1] = e[1];
	this->ennemy[2] = e[2];
	
}

void Game::game() {
	ennemy[0].attack(player);
	while (!player.isDead() && (!ennemy[0].isDead() || !ennemy[1].isDead() || !ennemy[2].isDead())) {
		this->turn += 1;
		this->turnPlayer();
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
