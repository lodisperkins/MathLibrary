#pragma once
#include "vector3.h"
class Matrix3
{
private:
	
public:
	float grid[3][3];
	Matrix3();
	Matrix3(float grid[3][3]);
	void rotate(float);
	Matrix3 operator * (Matrix3);
	Matrix3 operator * (Vector3);
};