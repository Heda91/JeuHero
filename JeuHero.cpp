#include "Perso.h"
#include "Game.h"
#include <iostream>
using namespace std;

int main()
{
    Perso a("Hero", 20);
    Perso b("Mechant1", 1);
    Perso c("Mechant2", 10);
    Perso d("Mechant3", 10);
    Perso e[3] = { b,c,d };
    Game g(a, e);
    g.game();
    return 0;
}
