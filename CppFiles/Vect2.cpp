#include "Vect2.h"
#include <math.h>

Vect2 Vect2::operator + (Vect2& otherVector) const
{
    return Vect2(x + otherVector.x, y + otherVector.y);
}

Vect2 Vect2::operator - (Vect2& otherVector)const 
{
    return Vect2(x - otherVector.x, y - otherVector.y);
}

Vect2 Vect2::operator * (float value)const 
{
    return Vect2(x * value, y * value);
}

Vect2 Vect2::operator / (float value)const 
{
    return Vect2(x / value, y / value);
}

Vect2& Vect2::operator += (Vect2& otherVector)
{
    x += otherVector.x;
    y += otherVector.y;
    return *this;
}

Vect2& Vect2::operator -= (Vect2& otherVector)
{
    x -= otherVector.x;
    y -= otherVector.y;
    return *this;
}

Vect2& Vect2::operator *= (float value)
{
    x *= value;
    y *= value;
    return *this;
}

Vect2& Vect2::operator /= (float value)
{
    x /= value;
    y /= value;
    return *this;
}

float Vect2::lenghSquared()
{
    return (x*x + y*y); 
}

Vect2 Vect2::normalize()
{
    float lengthSquared = sqrt(this->lenghSquared());
    Vect2 norm = *this;
    norm /= lengthSquared;
    return norm;
}

Vect2 Vect2::normalize(Vect2& other)
{
    Vect2 distance = *this - other;
    Vect2 norm = distance.normalize();
    return norm;
}

std::ostream& operator << (std::ostream& out, Vect2& vector)
{
    out << "[" << vector.x << "," << vector.y << "]" << std::endl;
    return out;
}