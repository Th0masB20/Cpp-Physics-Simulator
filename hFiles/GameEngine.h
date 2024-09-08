#include "SFML/Graphics.hpp"
#include <iostream>
#include <map>

class GameEngine{
    private:
        sf::RenderWindow m_window;
        bool running = false;
        //entity mannager
        std::map<int, std::string> actionMap; 
    public:
        void init();
        void update();
        void run();
        void quit();
        sf::RenderWindow& window();
};