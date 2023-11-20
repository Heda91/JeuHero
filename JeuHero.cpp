#include "Perso.h"
#include "Game.h"
#include "Weapon.h"
#include <iostream>
using namespace std;

int main()
{
    Weapon* hache = new Weapon(5);
    Weapon* main = new Weapon(2);
    Perso a("Hero", 20, hache);
    Perso b("Mechant1", 1, main);
    Perso c("Mechant2", 10, main);
    Perso d("Mechant3", 10, main);
    Perso e[3] = { b,c,d };
    Game g(a, e);
    g.game();
    return 0;
}
