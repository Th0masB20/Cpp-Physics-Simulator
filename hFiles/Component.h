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
        float velocity;
        float acceleration;

    public:
        CTransform(const Vect2 &position, float velocity, float acceleration)
            : position(position), velocity(velocity), acceleration(acceleration){};

        CTransform(const Vect2 &position, float velocity)
            : position(position), velocity(velocity), acceleration(0){};

        CTransform(const Vect2 &position)
            : position(position), velocity(0), acceleration(0){};

        CTransform()
            : position(Vect2(0,0)), velocity(0), acceleration(0){};
        Vect2& getPosition();
        float getVelocity();
        float getAcceleration();
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
        }
        sf::CircleShape& getShape();
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