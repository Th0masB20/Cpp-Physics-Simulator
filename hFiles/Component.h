#pragma once
#include "Vect2.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>

class Component
{
    public:
        bool has = false;
};

class CTransform : public Component
{
    private:
        Vect2 position;
        Vect2 previousPosition;
        Vect2 velocity;
        Vect2 acceleration;

    public:
        CTransform(const Vect2 &position, Vect2& velocity, Vect2& acceleration)
            : position(position), velocity(velocity), acceleration(acceleration){};

        CTransform(const Vect2 &position, Vect2& velocity)
            : position(position), velocity(velocity), acceleration(Vect2(0,0)){};

        CTransform(const Vect2 &position)
            : position(position), velocity(Vect2(0,0)), acceleration(Vect2(0,0)){};

        CTransform()
            : position(Vect2(0,0)), velocity(Vect2(0,0)), acceleration(Vect2(0,0)){};
        const Vect2& getPosition() const;
        const Vect2& getPreviousPostion() const;
        const Vect2& getVelocity() const;
        const Vect2& getAcceleration() const;
        void setPosition(Vect2 newPosition);
        void setVelocity(Vect2 newPosition);
        void setAcceleration(Vect2& newPosition);
};

class CShape : public Component
{   
    private:
        sf::CircleShape shape;
        int points;
        float radius;

    public:
        CShape():points(0), radius(0){}
        CShape(float radius, int points):points(points), radius(radius)
        {
            shape = sf::CircleShape(radius, points);
            //center origin
            shape.setOrigin(radius, radius);
        }

        void setPosition(Vect2 position);
        sf::CircleShape& getShape();
};

class CLineShape : public Component
{
    private:
        sf::RectangleShape line;
        float width;
        float length;

    public:
        CLineShape():width(0), length(0){};
        CLineShape(float length, float width): width(width), length(length) 
        {
            line = sf::RectangleShape({length, width});
        }

        void setPosition(Vect2 position);
        void setLineLength(float length);
        sf::RectangleShape& getLine();
};

class CCollision : public Component
{
    private:
        int radius;

    public:
        CCollision():radius(0){}
        CCollision(int radius):
            radius(radius){}

        int getRadius()
        {
            return radius;
        }
};

class CGravity : public Component
{
    private:
        float gravity;
    
    public: 
        CGravity() {}
};