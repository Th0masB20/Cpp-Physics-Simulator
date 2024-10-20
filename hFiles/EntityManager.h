#pragma once
#include <vector>
#include "Entity.h"
#include <map>
#include <memory>

//vector of Enity Pointers
using EntityVector = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVector>;

class EntityManager
{
    private:
        size_t m_totalEntities = 0;
        EntityVector m_entities;
        EntityMap m_tagToEntity;
        EntityVector m_toAdd;
        EntityVector m_toRemove;

    public:
        void update();
        const std::shared_ptr<Entity> addEntity(std::string tag);
        const std::shared_ptr<Entity> removeEntity(size_t id);
        const EntityVector& getEntity() const;
        const EntityVector& getEntity(std::string tag);
        const std::shared_ptr<Entity> getEntity(size_t id);
};