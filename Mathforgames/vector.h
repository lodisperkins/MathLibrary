#pragma once

class Vector2
{
private:
	float xpos;
	float ypos;
public:
	Vector2();
	Vector2(int newX, int newY)
	{
		xpos = newX;
		ypos = newY;
	}
	int x;
	int y;
};