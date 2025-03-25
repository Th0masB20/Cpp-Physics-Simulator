#include "GameScene.h"
#include "Component.h"
#include <math.h>

void GameScene::init()
{
    registerAction(sf::Keyboard::T, "TRIANGLE");
    registerAction(sf::Keyboard::S, "SQUARE");
    registerAction(sf::Mouse::Left - 2, "SPAWN");
}

void GameScene::sDoAction(Action action)
{
    //all start ations
    if(action.getType() == "START")
    {
        if(action.getName() == "TRIANGLE")
        {
            selectedParticle = "triangle";
        }

        if(action.getName() == "SQUARE")
        {
            selectedParticle = "square";
        }

        if(action.getName() == "SPAWN")
        {
            if(std::find(particalVector.begin(), particalVector.end(), selectedParticle) == particalVector.end()) return;
            Vect2 mousePos = action.getMousePosition();
            spawnClick = std::make_shared<Vect2>(mousePos.x, mousePos.y);
            GameScene::startMouseTracking();

            if(selectedParticle == "triangle")
            {
                auto& entity = m_EntityManager.addEntity("triangle");
                entity->addComponent<CShape>(particleRadius,3).setPosition(mousePos);
            }

            if(selectedParticle == "square")
            {
                auto& entity = m_EntityManager.addEntity("square");
                entity->addComponent<CShape>(particleRadius,4).setPosition(mousePos);
            }

            auto& lineEntity = m_EntityManager.addEntity("line");
            lineEntity->addComponent<CLineShape>(0, 3).setPosition(Vect2(0,0));
            lineEntity->addComponent<CTransform>(Vect2(spawnClick->x, spawnClick->y));
            lineEntity->getComponent<CLineShape>().getLine().setRotation(0);

            selectedParticle = "";
        }
    }

    //all end actions
    else if (action.getType() == "END")
    {
        if(action.getName() == "SPAWN")
        {
            if(spawnClick == nullptr) return;
            auto& line = m_EntityManager.getEntity("line");
            if(line.size() > 0) line[0]->destroy();
            
            Vect2 endPos = action.getMousePosition();
            Vect2 startPos = Vect2(spawnClick->x, spawnClick->y);
            float speed = sqrt(Vect2::lenghSquared(startPos, endPos)) * 0.001;
            Vect2 velocity = endPos.normalize(startPos) * speed;

            for(auto& entity: m_EntityManager.getEntity())
            {
                if(!entity->getComponent<CTransform>().has)
                {
                    entity->addComponent<CTransform>(startPos, velocity);
                }

                if(!entity->getComponent<CCollision>().has)
                {
                    entity->addComponent<CCollision>(5);
                }
            }
        }
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

        if(entity->getComponent<CLineShape>().has)
        {
            m_window.draw(entity->getComponent<CLineShape>().getLine());
        }
    }
}

void GameScene::update(sf::RenderWindow& window)
{
    //creates line
    if(isMouseTracked())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        Vect2 currentMousePos(mousePos.x, mousePos.y);
        Vect2 startPos = Vect2(getSpawnClick()->x, getSpawnClick()->y);

        float lengthSq = Vect2::lenghSquared(currentMousePos, startPos);
        float length = sqrt(lengthSq);
        Vect2 normalizedDirection = currentMousePos.normalize(startPos); 
        float angle = atan2(normalizedDirection.y, normalizedDirection.x) * 180/M_PI ;
        
        auto& lineEntity = m_EntityManager.getEntity("line");
        if(lineEntity.size() > 0)
        {
            lineEntity[0]->getComponent<CLineShape>().setLineLength(length);
            lineEntity[0]->getComponent<CLineShape>().setPosition(startPos);
            lineEntity[0]->getComponent<CLineShape>().getLine().setRotation(angle);
        }
    }
    m_EntityManager.update();

    for(auto& entity : m_EntityManager.getEntity())
    {
        if(entity->getComponent<CTransform>().has)
        {          
            Vect2 position = entity->getComponent<CTransform>().getPosition();
            Vect2 velocity = entity->getComponent<CTransform>().getVelocity();
            Vect2 newPos = position + velocity;
            entity->getComponent<CTransform>().setPosition(newPos);
            
            sCheckCollision(window);
        }

        //updates viewable position
        if(entity->getComponent<CShape>().has && entity->getComponent<CTransform>().has)
        {
            const Vect2& position = entity->getComponent<CTransform>().getPosition();
            entity->getComponent<CShape>().setPosition(position);
        }
    }
}

void GameScene::sCheckCollision(sf::RenderWindow& window)
{
    for(auto& entity : m_EntityManager.getEntity())
    {
        if(entity->getComponent<CCollision>().has && entity->getComponent<CTransform>().has)
        {
            float radius = entity->getComponent<CCollision>().getRadius();
            auto& transform = entity->getComponent<CTransform>();

            const Vect2& velocity = transform.getVelocity();
            const Vect2& position = transform.getPosition();

            if(transform.getPosition().x < radius)
            {
                transform.setPosition(Vect2(radius,position.y));
                Vect2 newVel(velocity.x * -1, velocity.y);
                transform.setVelocity(newVel);
            }
            if(window.getSize().x - transform.getPosition().x < radius)
            {
                transform.setPosition(Vect2(window.getSize().x - radius,position.y));
                Vect2 newVel(velocity.x * -1, velocity.y);
                transform.setVelocity(newVel);
            }
            if(transform.getPosition().y < radius)
            {
                transform.setPosition(Vect2(position.x,radius));
                Vect2 newVel(velocity.x, velocity.y*-1);
                transform.setVelocity(newVel);
            }
            if(window.getSize().y - transform.getPosition().y < radius)
            {
                transform.setPosition(Vect2(position.x,window.getSize().x - radius));
                Vect2 newVel(velocity.x, velocity.y*-1);
                transform.setVelocity(newVel);
            }
        }
    }
}

void GameScene::sCheckEntityCollision(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
{
    if(!a->getComponent<CCollision>().has && !a->getComponent<CTransform>().has
        && !b->getComponent<CCollision>().has && !b->getComponent<CTransform>().has) 
        return;

    auto &a_collision = a->getComponent<CCollision>();
    auto &b_collision = b->getComponent<CCollision>();

    auto &a_transform = a->getComponent<CTransform>();
    auto &b_transform = b->getComponent<CTransform>();

    float distance = Vect2::lenghSquared(a_transform.getPosition(), b_transform.getPosition());
}

const std::shared_ptr<Vect2> GameScene::getSpawnClick() const
{
    return spawnClick;
}
