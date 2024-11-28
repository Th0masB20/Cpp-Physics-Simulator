#pragma once
#include "SFML/Graphics.hpp"
#include "EntityManager.h"
#include "Entity.h"
#include <iostream>
#include <map>
#include "Scene.h"  
#include "GameScene.h"

class GameEngine{
    private:
        sf::RenderWindow m_window;
        std::map<std::string, std::shared_ptr<Scene>> m_sceneMap; 
        bool m_running = false;

    public:
        void init(); //initializes window 
        void update(); //updates everything in windows
        void run(); // called once to start game
        void quit();
        void sUserInput(sf::Event event);
        void sRender();
        sf::RenderWindow& window(); 
};