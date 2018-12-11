#include "vector2.h"
#include<cmath>
Vector2::Vector2()
{
}

Vector2::Vector2(float newX, float newY)
{
}

float Vector2::getX()
{
	return xpos;
}

float Vector2::getY()
{
	return ypos;
}

Vector2 Vector2::operator+(Vector2 & rhs)
{
	return Vector2(xpos + rhs.getX(), ypos + rhs.getY());
}

Vector2 Vector2::operator-(Vector2 & rhs)
{
	return Vector2(xpos - rhs.getX(), ypos - rhs.getY());
}

bool Vector2::operator==(Vector2 & rhs)
{
	return (xpos == rhs.getX() && ypos == rhs.getY());
}

bool Vector2::operator!=(Vector2 & rhs)
{
	return (xpos != rhs.getX() || ypos != rhs.getY());
}

float Vector2::magnitude()
{
	//pow(x,y) and sqrt(x)
	return sqrt(pow(xpos, 2) + pow(ypos, 2));
}

Vector2 Vector2::operator*(float &scalar)
{
	return Vector2(xpos*scalar,ypos *scalar);
}

Vector2 Vector2::normalize()
{
	return Vector2(xpos/magnitude(),ypos/magnitude());
}

float Vector2::distance(Vector2& rhs)
{
	Vector2 newvec(xpos - rhs.getX(), ypos - rhs.getY());
	return newvec.magnitude();
}


//Distance = Vector 2 - Vector 1 then find magnitude of new vector
