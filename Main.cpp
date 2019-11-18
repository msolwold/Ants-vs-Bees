/**
 * Main
 */

#include "Core/Game.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
    Game * g = new Game();

    int result = g->run();

    if (result == 1) cout << endl << "You Won!!" << endl;
    if (result == 0) cout << endl << "You Lost??" << endl;

    delete g;
    return 1;
}