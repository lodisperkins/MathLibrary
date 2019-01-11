#include "Vector4.h"
#include <cmath>
Vector4::Vector4()
{
}

Vector4::Vector4(float newX, float newY, float newZ,float newT)
{
	xpos = newX;
	ypos = newY;
	zpos = newZ;
	trans = newT;
}

float Vector4::getX()
{
	return xpos;
}

float Vector4::getY()
{
	return ypos;
}

float Vector4::getZ()
{
	return zpos;
}
float Vector4::getT()
{
	return trans;
}
Vector4 Vector4::operator+(Vector4 & rhs)
{
	return Vector4(xpos + rhs.getX(), ypos + rhs.getY(), zpos + rhs.getZ(), trans+rhs.getT());
}

Vector4 Vector4::operator-(Vector4 & rhs)
{
	return Vector4(xpos - rhs.getX(), ypos - rhs.getY(), zpos - rhs.getZ(),trans - rhs.getT());
}

bool Vector4::operator==(Vector4 & rhs)
{
	return (xpos == rhs.getX() && ypos == rhs.getY() && zpos == rhs.getZ()&& trans == rhs.getT());
}

bool Vector4::operator!=(Vector4 & rhs)
{
	return (xpos != rhs.getX() || ypos != rhs.getY() || zpos != rhs.getZ()|| trans != rhs.getT());
}

float Vector4::magnitude()
{
	//pow(x,y) and sqrt(x)
	return sqrt(pow(xpos, 2) + pow(ypos, 2) + pow(zpos, 2) + pow(trans, 2));
}

Vector4 Vector4::operator*(float &scalar)
{
	return Vector4(xpos*scalar, ypos *scalar, zpos*scalar, trans *scalar);
}

Vector4 Vector4::normalize()
{
	return Vector4(xpos / magnitude(), ypos / magnitude(), zpos / magnitude(), trans / magnitude());
}

float Vector4::dotproduct(Vector4 & rhs)
{
	return (xpos*rhs.getX()) + (ypos*rhs.getY()) + (zpos*rhs.getZ()) + (trans*rhs.getT());
}


float Vector4::distance(Vector4& rhs)
{
	Vector4 newvec(xpos - rhs.getX(), ypos - rhs.getY(), zpos - rhs.getZ(), trans);
	return newvec.magnitude();
}
