#include "GameEngine.h"
#include "GameScene.h"
#include <math.h>

void GameEngine::init()
{
    m_window.create(sf::VideoMode(400,400), "Physics Simulator");
    m_sceneMap["main"] = std::make_shared<GameScene>();
    m_sceneMap["main"]->init();
}

sf::RenderWindow& GameEngine::window()
{
    return m_window;
}

void GameEngine::quit()
{
    m_running = false;
}

void GameEngine::sRender()
{
    m_window.clear(sf::Color::Black);
    //render anything on the scene
    m_sceneMap["main"]->sRender(m_window);
    m_window.display();
}

void GameEngine::sUserInput(sf::Event event)
{
    if(event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased )
    {
        int code = event.key.code;
        //if the code isnt in the action map, return
        if(m_sceneMap["main"]->getActionMap().find(code) == m_sceneMap["main"]->getActionMap().end()) 
        {
            return;
        }
        
        std::string actionType = event.type == sf::Event::KeyPressed ? "START" : "END";
        Action action(actionType, m_sceneMap["main"]->getActionMap().at(code));
        m_sceneMap["main"]->doAction(action);
    }

    if(event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
    {
        //-2 is left (0 - 2) and right is -1 (1 - 2)
        int code = event.mouseButton.button  == 0 ? -2 :-1;

        //if the code isnt in the action map, return
        if(m_sceneMap["main"]->getActionMap().find(code) == m_sceneMap["main"]->getActionMap().end()) 
        {
            return;
        }

        Vect2 mousePosition(event.mouseButton.x, event.mouseButton.y);
        std::string actionType = event.type == sf::Event::MouseButtonPressed ? "START" : "END";
        Action action(actionType, m_sceneMap["main"]->getActionMap().at(code), mousePosition);
        m_sceneMap["main"]->doAction(action);
    }
}

void GameEngine::run()
{
    m_running = true;

    while(m_running)
    {
        sf::Event event;
        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                quit();
            }

            sUserInput(event);
        }
        m_sceneMap["main"]->update(m_window);
        sRender();
    }
}
