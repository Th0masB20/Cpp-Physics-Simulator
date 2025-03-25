#pragma once
#include <iostream>

class Vect2
{
    public:
        float x, y;

        Vect2():x(0), y(0){};
        Vect2(float x, float y):x(x), y(y){};

        Vect2 normalize();
        Vect2 normalize(Vect2& otherVector);
        float lenghSquared();
        static float lenghSquared(const Vect2& vector1, const Vect2& vector2);
        static float lenghSquared(Vect2& vector1, Vect2& vector2);

        Vect2 operator - (Vect2& otherVector)const;
        Vect2 operator - (const Vect2& otherVector)const;

        Vect2 operator + (Vect2& otherVector)const;
        Vect2 operator * (float value)const; 
        Vect2 operator / (float value)const;
       
        Vect2& operator -= (Vect2& otherVector);
        Vect2& operator += (Vect2& otherVector);
        Vect2& operator *= (float value); 
        Vect2& operator /= (float value);

        friend std::ostream& operator << (std::ostream& out, Vect2& vector);
};
