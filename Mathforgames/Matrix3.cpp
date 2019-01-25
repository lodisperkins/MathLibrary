#include "Matrix3.h"
#include <cstring>
#include <cmath>
Matrix3::Matrix3()
{
	float newgrid[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
	memcpy(grid, newgrid,sizeof(newgrid));
}

Matrix3::Matrix3(float a,float b,float c, float d, float e,float f, float g,float h, float i)
{
	float newgrid[3][3] = { {a,b,c},{d,e,f},{g,h,i} };
	memcpy(grid, newgrid, sizeof(newgrid));
}
void Matrix3::setRotateX(float value)
{
	grid[1][1] = cos(value);
	grid[2][1] = sin(value);
	grid[1][2] = -sin(value);
	grid[2][2] = cos(value);
}
void Matrix3::setRotateY(float value)
{
	grid[0][0] = cos(value);
	grid[2][0] = sin(value);
	grid[0][2] = -sin(value);
	grid[2][2] = cos(value);
}
void Matrix3::setRotateZ(float value)
{
	grid[0][0] = cos(value);
	grid[1][0] = sin(value);
	grid[0][1] = -sin(value);
	grid[1][1] = cos(value);
}

Matrix3 Matrix3::operator*(Matrix3 other)
{
	int h = 0;
	float newgrid[3][3];
	float newValue=0;
	Matrix3 answer;
	for (int i=0; i <= 2; i++)
	{
		for (int j=0; j <= 2; j++)
		{
			for (int h = 0; h <= 2; h++)
			{
				newValue = newValue +(grid[i][h] * other.grid[h][j]);
			}
			answer.grid[i][j] = newValue;
			newValue = 0;
		}
	}
	return answer;
}

Vector3 Matrix3::operator*(Vector3 vec)
{
	float newValue = 0;
	float vecValues[3] = { vec.getX(),vec.getY(),vec.getZ() };
	float answerVal[3];
	for (int j = 0; j <= 2; j++)
	{
		for (int h = 0; h <= 2; h++)
		{
			newValue = newValue + (grid[j][h] * vecValues[h]);
		}
		answerVal[j] = newValue;
		newValue = 0;
	}
	
	return Vector3(answerVal[0], answerVal[1], answerVal[2]);
}

Vector3 Matrix3::operator[](int index)
{
	Vector3 result;
	float newgrid[9];
	for (int i = 0; i <= 8;)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int h = 0; h <= 2; h++)
			{
				newgrid[i]=grid[h][j];
				i++;
			}

		}
	}
	Vector3 sum(newgrid[index * 3], newgrid[(index * 3) + 1], newgrid[(index * 3) + 2]);
	result = sum;
	return result;
}

Matrix3::operator float*()
{
	float * data;
	float newgrid[9];
	for (int i = 0; i <= 8;)
	{
		for (int j = 0; j <= 2; j++)
		{
			for (int h = 0; h <= 2; h++)
			{
				newgrid[i] = grid[h][j];
				i++;
			}

		}
	}
	return data = newgrid;
}
