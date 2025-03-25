#pragma once

#include "Scene.h"
#include "SFML/Graphics.hpp"
#include "Action.h"
#include <memory.h>

class GameScene : public Scene
{
    private:
        const int particleRadius = 6;
        std::string selectedParticle = "";
        std::vector<std::string> particalVector = {"triangle", "square"};
        std::shared_ptr<Vect2> spawnClick; 

    public:
        virtual const std::shared_ptr<Vect2> getSpawnClick() const;

        virtual void init() override;
        //change this when finish implementing Action class
        virtual void sDoAction(Action action) override;

        virtual void doAction(Action action) override;

        virtual void sCheckCollision(sf::RenderWindow& window) override;
        virtual void sCheckEntityCollision(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) override;
        virtual void sRender(sf::RenderWindow& m_window) override;
        virtual void update(sf::RenderWindow& m_window) override;
};

