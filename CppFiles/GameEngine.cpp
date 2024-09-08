#include "GameEngine.h"

void GameEngine::init()
{
    m_window.create(sf::VideoMode(400,400), "Physics Simulator");
}

void GameEngine::run()
{
    running = true;

    while(running)
    {
        update();
        sf::Event event;
        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                quit();
            }
        }
    }
}

void GameEngine::quit()
{
    running = false;
}

void GameEngine::update()
{
    //entity manager update
    //inputs 
    //physics
}

sf::RenderWindow& GameEngine::window()
{
    return m_window;
}