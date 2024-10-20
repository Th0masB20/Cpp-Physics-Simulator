#include "GameEngine.h"
#include "EntityManager.h"

void GameEngine::init()
{
    m_window.create(sf::VideoMode(400,400), "Physics Simulator");
}

void GameEngine::run()
{
    m_running = true;

    while(m_running)
    {
        update();
        sf::Event event;
        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                quit();
            }
            
            if(event.type == sf::Event::KeyPressed)
            {
                int code = event.key.code;
                if(code == sf::Keyboard::T)
                {
                    auto entity = m_EntityManager.addEntity("Player");
                    entity->addComponent<CShape>(10,10);
                }
                
                if(code == sf::Keyboard::G)
                {
                    m_EntityManager.removeEntity(0);
                }
            }
        }

        sRender();
    }
}

void GameEngine::sRender()
{
    m_window.clear(sf::Color::Black);
    for(auto& entity : m_EntityManager.getEntity())
    {
        if(entity->getComponent<CShape>().has)
        {
            m_window.draw(entity->getComponent<CShape>().getShape());
        }
    }
    m_window.display();
}

void GameEngine::quit()
{
    m_running = false;
}

void GameEngine::update()
{
    m_EntityManager.update();
    //inputs 
    //physics
}

sf::RenderWindow& GameEngine::window()
{
    return m_window;
}