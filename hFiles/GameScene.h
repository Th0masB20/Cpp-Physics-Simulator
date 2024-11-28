#pragma once

#include "Scene.h"
#include "SFML/Graphics.hpp"
#include "Action.h"

class GameScene : public Scene
{
    private:
        std::string selectedParticle = "";
    public:
        virtual void init() override;

        //change this when finish implementing Action class
        virtual void sDoAction(Action action) override;

        virtual void doAction(Action action) override;

        virtual void sRender(sf::RenderWindow& m_window) override;
        virtual void update() override;
};

