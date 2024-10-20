#pragma once 
#include <iostream>
#include <tuple>
#include "Component.h"

class Entity
{
    private:
        std::string tag;
        size_t id;
        bool alive = false;
        std::tuple<CTransform, CCollision, CShape> m_Components;
        Entity(std::string tag, int id):tag(tag), id(id), alive(true) {}

    public:
        std::string& getTag();
        size_t getId();
        bool isAlive();
        void destroy();

        template<typename C>
        C& getComponent()
        {
            return std::get<C>(m_Components);
        }

        template<typename C, typename... Args>
        C &addComponent(Args&&... args)
        {
            //gets reference to component
            auto &component = std::get<C>(m_Components);
            //sets reference to a new instance of the component
            component = C(std::forward<Args>(args)...);
            component.has = true;
            //returns new component
            return component;
        }

        template<typename C>
        bool hasComponent()
        {
            return getComponent<C>().has;
        }

        template<typename C>
        void removeComponent()
        {
            auto& component = getComponent<C>();
            component = C();
        }

        friend class EntityManager;
};