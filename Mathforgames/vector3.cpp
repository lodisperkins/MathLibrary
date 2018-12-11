#include "vector3.h"
#include <cmath>
Vector3::Vector3()
{
}

float Vector3::getX()
{
	return xpos;
}

float Vector3::getY()
{
	return ypos;
}

float Vector3::getZ()
{
	return zpos;
}

Vector3 Vector3::operator+(Vector3 & rhs)
{
	return Vector3(xpos + rhs.getX(), ypos + rhs.getY(),zpos +rhs.getZ());
}

Vector3 Vector3::operator-(Vector3 & rhs)
{
	return Vector3(xpos - rhs.getX(), ypos - rhs.getY(),zpos-rhs.getZ());
}

bool Vector3::operator==(Vector3 & rhs)
{
	return (xpos == rhs.getX() && ypos == rhs.getY()&& zpos == rhs.getZ());
}

bool Vector3::operator!=(Vector3 & rhs)
{
	return (xpos != rhs.getX() || ypos != rhs.getY() || zpos != rhs.getZ());
}

float Vector3::magnitude()
{
	//pow(x,y) and sqrt(x)
	return sqrt(pow(xpos, 2) + pow(ypos, 2)+pow);
}

Vector2 Vector2::operator*(float &scalar)
{
	return Vector2(xpos*scalar, ypos *scalar);
}

Vector2 Vector2::normalize()
{
	return Vector2(xpos / magnitude(), ypos / magnitude());
}

float Vector2::distance(Vector2& rhs)
{
	Vector2 newvec(xpos - rhs.getX(), ypos - rhs.getY());
	return newvec.magnitude();
}


//Distance = Vector 2 - Vector 1 then find magnitude of new vector

