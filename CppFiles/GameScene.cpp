#include "GameScene.h"
#include "Component.h"

void GameScene::init()
{
    registerAction(sf::Keyboard::T, "TRIANGLE");
    registerAction(sf::Keyboard::G, "SQUARE");
    registerAction(sf::Mouse::Left - 2, "SPAWN");
}

void GameScene::sDoAction(Action action)
{
    //all start ations
    if(action.getType() == "START")
    {
        std::cout << (action.getName() == "SPAWN" )<< std::endl;
        if(action.getName() == "TRIANGLE")
        {
            GameScene::selectedParticle = "triangle";
        }

        if(action.getName() == "SQUARE")
        {
            GameScene::selectedParticle = "square";
        }

        if(action.getName() == "SPAWN")
        {
            auto mousePos = action.getMousePosition();
            if(GameScene::selectedParticle == "triangle")
            {
                auto& entity = m_EntityManager.addEntity("Triangle");
                entity->addComponent<CShape>(6,3);
                entity->addComponent<CTransform>(action.getMousePosition());
                entity->getComponent<CShape>().setPosition(mousePos);
            }

            if(GameScene::selectedParticle == "square")
            {
                auto& entity = m_EntityManager.addEntity("square");
                entity->addComponent<CShape>(6,4);
                entity->addComponent<CTransform>(action.getMousePosition());
                entity->getComponent<CShape>().setPosition(mousePos);
            }
        }
    }

    //all end actions
    else if (action.getType() == "END")
    {

    }
}

void GameScene::doAction(Action action) 
{
    sDoAction(action);
}

void GameScene::sRender(sf::RenderWindow& m_window)
{
    for(auto& entity : m_EntityManager.getEntity())
    {
        if(entity->getComponent<CShape>().has)
        {
            m_window.draw(entity->getComponent<CShape>().getShape());
        }
    }
}

void GameScene::update()
{
    //implement for updating collision and position and adding entities
    m_EntityManager.update();
}   
