#pragma once
#include "Action.h"
#include "EntityManager.h"
#include <map>
#include <iostream>
#include <string>

//Scene Base Class
class Scene
{
    protected:
        std::map<int, std::string> m_actionMap; //sfml key code to action type
        EntityManager m_EntityManager; // entityManager of the scene
        int m_currentFrame; 
        bool trackMouse = false;

        virtual void sDoAction(Action action) = 0;
        void registerAction(int code, std::string action)
        {
            //sets a key code to an action string
            m_actionMap[code] = action;
        };

    public:      
        bool isMouseTracked()
        {
            return trackMouse;
        }

        void startMouseTracking()
        {
            trackMouse = true;
        }

        void stopMouseTracking()
        {
            trackMouse = false;
        }

        virtual const std::shared_ptr<Vect2> getSpawnClick() const = 0;
        virtual void init() = 0;
        virtual void update(sf::RenderWindow& m_window) = 0; 
        virtual void sRender(sf::RenderWindow& m_window) = 0;
        virtual void doAction(Action action) = 0;
        virtual void sCheckCollision(sf::RenderWindow& window) = 0;
        virtual void sCheckEntityCollision(std::shared_ptr<Entity>a, std::shared_ptr<Entity> b) = 0;
        const std::map<int, std::string>& getActionMap() const
        {
            return m_actionMap;
        }
};