#pragma once
#include "vector3.h"
class Matrix3
{
private:
	float grid[3][3];
	
public:
	Matrix3();
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	void setRotateZ(float);
	void setRotateX(float value);
	void setRotateY(float);
	Matrix3 operator * (Matrix3);
	Vector3 operator * (Vector3);
	Vector3 operator [](int index);
	operator float*();
};