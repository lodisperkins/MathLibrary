#include "Matrix3.h"
#include <cstring>
Matrix3::Matrix3()
{
	float newgrid[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
	memcpy(grid, newgrid,sizeof(newgrid));
}

Matrix3::Matrix3(float newgrid[3][3])
{
	memcpy(grid, newgrid, sizeof(newgrid));
}

void Matrix3::rotate(float value)
{
	grid[0][0] = grid[0][0] -value;
	grid[1][0] = grid[1][0] + value;
	grid[0][1] = grid[0][1] - value;
	grid[1][1] = grid[1][1] - value;
}

Matrix3 Matrix3::operator*(Matrix3 other)
{
	int h = 0;
	float newgrid[3][3];
	float newValue;
	for (int i=0; i <= 2; i++)
	{
		for (int j=0; j <= 2; j++)
		{
			for (int h = 0; h <= 2; h++)
			{
				newValue = newValue +(grid[i][h] * other.grid[h][j]);
			}
			newgrid[i][j] = newValue;
		}
	}
	return Matrix3(newgrid);
}
