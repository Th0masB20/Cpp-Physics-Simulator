#include "Entity.h"

bool Entity::isAlive()
{
    return alive;
}

size_t Entity::getId()
{
    return id;
}

std::string& Entity::getTag()
{
    return tag;
}

void Entity::destroy()
{
    alive = false;
}