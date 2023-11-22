#pragma once
#include "Perso.h"
#include <string>

class Effect
{
private:
	int turn;
	std::string name;
	virtual void playEndTurn(Perso&);//joue l'effet en fin de tour
public:
	Effect(std::string name, int turn);
	std::string getName();
	int getTurn();
	void setTurn(int);
	bool advanceTurn(Perso&); //fait tour-1 et renvoi si c'est la fin de l'effet
	virtual void play(Perso&); //joue l'effet
};

class Burn : public Effect
{
private:
	int damage;
public:
	Burn(std::string name, int turn, int damage) ;
	void play(Perso& p) override;
};

