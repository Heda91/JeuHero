#pragma once
#include "Perso.h"
#include <vector>

class Effect;

class Game
{
private:
	unsigned int turn = 0;
	Perso player;
	Perso ennemy[3];
public:
	Game(Perso hero, Perso ennemy[3]);
	unsigned int getTurn();

	void game();
	void turnPlayer();
	void turnBot();
	void effectEndTurn(Perso*);
};

