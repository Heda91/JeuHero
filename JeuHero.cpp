#include "Perso.h"
#include "Game.h"
#include "Weapon.h"
#include "Effect.h"
#include <iostream>
using namespace std;

int main()
{
    Weapon* hache = new Weapon(5, 'P');
    Weapon* main_gauche = new Weapon(1, 'P');
    Weapon* main = new Weapon(2, 'P');
    Perso a("Hero", 20, hache);
    Perso b("Mechant1", 1, main_gauche);
    Perso c("Mechant2", 10, main);
    Perso d("Mechant3", 10, main);
    Perso e[3] = { b,c,d };
    Game g(a, e);
    g.game();
    return 0;
}
//*/
/*
int main()
{
    Weapon* hache = new Weapon(5, 'P', 1);
    Weapon* main_gauche = new Weapon(1, 'P');
    Weapon* main = new Weapon(2, 'P');
    Perso a("Hero", 20, hache);
    Perso b("Mechant1", 1, main_gauche);
    Perso c("Mechant")
    return 0;
}
//*/
