#include <iostream>
#include "Vect2.h"
#include "GameEngine.h"
int main(int argc, char** argv)
{
    GameEngine game;
    game.init();
    game.run();
    return 1;
}