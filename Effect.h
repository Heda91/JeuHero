#pragma once
#include "Perso.h"
#include <string>

class Effect
{
private:
	int turn;
	std::string name;
protected:
	Perso* perso;
	virtual void playEndTurn();//joue l'effet en fin de tour
public:
	Effect(Perso*, std::string name, int turn);
	std::string getName();
	int getTurn();
	void setTurn(int);
	bool advanceTurn(); //fait tour-1 et renvoi si c'est la fin de l'effet
	virtual void play(); //joue l'effet
};

class Burn : public Effect
{
private:
	int damage;
	void playEndTurn() override;
public:
	Burn(Perso*, std::string name, int turn, int damage = 2) ;
};

