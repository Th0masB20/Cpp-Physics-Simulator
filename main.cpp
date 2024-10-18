#include <iostream>
#include "GameEngine.h"
#include "Entity.h"
#include "Component.h"
int main(int argc, char** argv)
{
    GameEngine game;
    game.init();
    game.run();
    
    return 1;
}