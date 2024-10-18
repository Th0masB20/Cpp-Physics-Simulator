#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <map>

class GameEngine{
    private:
        sf::RenderWindow m_window;
        bool running = false;
        //entity mannager
        std::map<int, std::string> actionMap; //sfml key code to action type
    public:
        void init(); //initializes window 
        void update(); //updates everything in windows
        void run(); // called once to start game
        void quit();
        void sUserInput();
        sf::RenderWindow& window(); 
};