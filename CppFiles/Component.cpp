#include "Component.h"

const Vect2& CTransform::getPosition() const 
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

void CShape::setPosition(Vect2 position)
{
    shape.setPosition(sf::Vector2f(position.x, position.y));
}