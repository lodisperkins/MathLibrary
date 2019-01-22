#include "Matrix4.h"
#include <cmath>
#include <cstring>

Matrix4::Matrix4()
{
	float newgrid[4][4] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{0,0,0,0} };
	memcpy(grid, newgrid, sizeof(newgrid));
}

Matrix4::Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i,float j, float k,float l,float m,float n, float o, float p)
{
	float newgrid[4][4] = { { a,b,c,d },{ e,f,g,h },{ i,j,k,l },{m,n,o,p} };
	memcpy(grid, newgrid, sizeof(newgrid));
}
void Matrix4::rotateX(float value)
{
	grid[0][0] = grid[0][0] - value;
	grid[1][0] = grid[1][0] + value;
	grid[0][1] = grid[0][1] - value;
	grid[1][1] = grid[1][1] - value;
}
void Matrix4::rotateY(float value)
{
	grid[0][0] = cos(value);
	grid[2][0] = sin(value);
	grid[0][1] = grid[0][1] - value;
	grid[1][1] = grid[1][1] - value;
}
void Matrix4::rotateZ(float value)
{
	grid[0][0] = cos(value);
	grid[1][0] = sin(value);
	grid[0][1] = -sin(value);
	grid[1][1] = cos(value);
}

Matrix4 Matrix4::operator*(Matrix4 other)
{
	int h = 0;
	float newgrid[3][3];
	float newValue = 0;
	Matrix4 answer;
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			for (int h = 0; h <= 3; h++)
			{
				newValue = newValue + (grid[i][h] * other.grid[h][j]);
			}
			answer.grid[i][j] = newValue;
			newValue = 0;
		}
	}
	return answer;
}

Vector4 Matrix4::operator*(Vector4 vec)
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

	return Vector4(answerVal[0], answerVal[1], answerVal[2],answerVal[3]);
}
