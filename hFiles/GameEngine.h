#pragma once
#include "SFML/Graphics.hpp"
#include "EntityManager.h"
#include <iostream>
#include <map>

class GameEngine{
    private:
        sf::RenderWindow m_window;
        bool m_running = false;
        EntityManager m_EntityManager;
        std::map<int, std::string> actionMap; //sfml key code to action type
    public:
        void init(); //initializes window 
        void update(); //updates everything in windows
        void run(); // called once to start game
        void quit();
        void sUserInput();
        void sRender();
        sf::RenderWindow& window(); 
};