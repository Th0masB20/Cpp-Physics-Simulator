#include "Component.h"

const Vect2& CTransform::getPosition() const 
{
    return position;
}

const Vect2& CTransform::getVelocity() const
{
    return velocity;
}

void CTransform::setPosition(Vect2 newPosition)
{
    position = newPosition;
}
void CTransform::setVelocity(Vect2 newVelocity)
{
    velocity = newVelocity;
}

sf::CircleShape& CShape::getShape()
{
    return shape;
}

void CShape::setPosition(Vect2 position)
{
    shape.setPosition(sf::Vector2f(position.x, position.y));
}

void CLineShape::setPosition(Vect2 position)
{
    line.setPosition(sf::Vector2f(position.x, position.y));
}

void CLineShape::setLineLength(float length)
{
    this->length = length;
    line.setSize({length, width});
}

sf::RectangleShape& CLineShape::getLine()
{
    return line;
}

