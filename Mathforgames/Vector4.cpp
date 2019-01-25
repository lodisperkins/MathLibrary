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

Vector4 Vector4::operator*(float scalar)
{
	return Vector4(xpos*scalar, ypos *scalar, zpos*scalar, trans *scalar);
}

Vector4 Vector4::cross(Vector4 & rhs)
{
	return Vector4((ypos*rhs.getZ()) - (zpos*rhs.getY()), (zpos*rhs.getX()) - (xpos*rhs.getZ()), (xpos*rhs.getY()) - (ypos*rhs.getX()),0);
}

Vector4 Vector4::normalise()
{
	return Vector4(xpos / magnitude(), ypos / magnitude(), zpos / magnitude(), trans / magnitude());
}

float Vector4::dot(Vector4 & rhs)
{
	return (xpos*rhs.getX()) + (ypos*rhs.getY()) + (zpos*rhs.getZ()) + (trans*rhs.getT());
}


float Vector4::distance(Vector4& rhs)
{
	Vector4 newvec(xpos - rhs.getX(), ypos - rhs.getY(), zpos - rhs.getZ(), trans);
	return newvec.magnitude();
}

Vector4::operator float*()
{
	return mData;
}

Vector4 operator*(float scalar, Vector4 rhs)
{
	return Vector4(scalar*rhs.getX(),scalar*rhs.getY(),scalar*rhs.getZ(),0);
}
