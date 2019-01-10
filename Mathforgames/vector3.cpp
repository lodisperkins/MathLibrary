#include "vector3.h"
#include <cmath>
Vector3::Vector3()
{
}

Vector3::Vector3(float newX, float newY, float newZ)
{
	xpos = newX;
	ypos = newY;
	zpos = newZ;
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
	return sqrt(pow(xpos, 2) + pow(ypos, 2)+pow(zpos,2));
}

Vector3 Vector3::operator*(float &scalar)
{
	return Vector3(xpos*scalar, ypos *scalar,zpos*scalar);
}

Vector3 Vector3::normalize()
{
	return Vector3(xpos / magnitude(), ypos / magnitude(),zpos/magnitude());
}

float Vector3::dotproduct(Vector3 & rhs)
{
	return (xpos*rhs.getX())+(ypos*rhs.getY())+(zpos*rhs.getZ());
}

Vector3 Vector3::crossProduct(Vector3 & rhs)
{
	return Vector3((ypos*rhs.getZ())-(zpos*rhs.getY()),(zpos*rhs.getX())-(xpos*rhs.getZ()),(xpos*rhs.getY())-(ypos*rhs.getX()));
}

float Vector3::distance(Vector3& rhs)
{
	Vector3 newvec(xpos - rhs.getX(), ypos - rhs.getY(),zpos- rhs.getZ());
	return newvec.magnitude();
}


//Distance = Vector 2 - Vector 1 then find magnitude of new vector

