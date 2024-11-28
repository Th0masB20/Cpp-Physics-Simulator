#include <memory>
#include "EntityManager.h"

const std::shared_ptr<Entity> EntityManager::addEntity(std::string tag)
{
    std::shared_ptr<Entity> entity = std::make_shared<Entity>(Entity(tag, m_totalEntities));
    m_totalEntities++;
    m_toAdd.push_back(entity);
    return entity;
}

const EntityVector& EntityManager::getEntity() const
{
    return m_entities;
}

const EntityVector& EntityManager::getEntity(std::string tag)
{
    return m_tagToEntity[tag];
}

const std::shared_ptr<Entity> EntityManager::getEntity(size_t id)
{
    for(auto& entity : m_entities)
    {
        if(id == entity->getId())
        {
            return entity;
        }
    }

    return nullptr;
}

const std::shared_ptr<Entity> EntityManager::removeEntity(size_t id)
{
    auto &entity = getEntity(id);
    m_toRemove.push_back(entity);
    return entity;
}

void EntityManager::update()
{
    for(auto entity : m_toAdd)
    {
        m_entities.push_back(entity);
    }

    for(auto& removeEntity : m_toRemove)
    {
        m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), removeEntity), m_entities.end());
    }


    m_toRemove.clear();
    m_toAdd.clear();
}