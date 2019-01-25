#pragma once

class Vector4
{
private:
	float xpos;
	float ypos;
	float zpos;
	float trans;
	float vals[4] = { xpos,ypos,zpos,trans };
	float * mData = vals;
public:
	Vector4();
	Vector4(float newX, float newY, float newZ,float newT);
	float getX();
	float getY();
	float getZ();
	float getT();
	Vector4 operator +(Vector4& rhs);
	Vector4 operator - (Vector4& rhs);
	bool operator == (Vector4& rhs);
	bool operator != (Vector4& rhs);
	float magnitude();
	Vector4 operator* (float);
	friend Vector4 operator *(float, Vector4);
	Vector4 normalise();
	Vector4 cross(Vector4&rhs);
	float dot(Vector4&rhs);
	float distance(Vector4& rhs);
	operator float*();
	
};