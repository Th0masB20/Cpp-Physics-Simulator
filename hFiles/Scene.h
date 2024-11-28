#pragma once

#include <map>
#include <iostream>
#include <string>
#include "Action.h"
#include "EntityManager.h"

//Scene Base Class
class Scene
{
    protected:
        std::map<int, std::string> m_actionMap; //sfml key code to action type
        EntityManager m_EntityManager; // entityManager of the scene
        int m_currentFrame; 
        
        virtual void sDoAction(Action action) = 0;
        void registerAction(int code, std::string action)
        {
            //sets a key code to an action string
             m_actionMap[code] = action;
        };

    public:
        virtual void init() = 0;
        virtual void update() = 0; 
        virtual void sRender(sf::RenderWindow& m_window) = 0;
        virtual void doAction(Action action) = 0;
        const std::map<int, std::string>& getActionMap() const
        {
            return m_actionMap;
        }
};