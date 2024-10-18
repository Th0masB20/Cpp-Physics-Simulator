#include "Entity.h"

bool Entity::isActive()
{
    return active;
}

int Entity::getId()
{
    return id;
}

std::string& Entity::getTag()
{
    return tag;
}

void Entity::destroy()
{
    active = false;
}