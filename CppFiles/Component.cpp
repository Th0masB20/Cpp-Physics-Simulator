#include "Component.h"

Vect2& CTransform::getPosition()
{
    return position;
}

float CTransform::getVelocity()
{
    return velocity;
}

float CTransform::getAcceleration()
{
    return acceleration;
}

sf::CircleShape& CShape::getShape()
{
    return shape;
}