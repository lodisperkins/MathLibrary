#pragma once

class Vector2
{
private:
	float xpos;
	float ypos;
	float vals[2] = { xpos,ypos };
	float * mData =vals;
public:
	Vector2();
	Vector2(float newX, float newY);
	float getX();
	float getY();
	Vector2 operator +(Vector2& rhs);
	Vector2 operator - (Vector2& rhs);
	bool operator == (Vector2& rhs);
	bool operator != (Vector2& rhs);
	float magnitude();
	Vector2 operator* (float);
	friend Vector2 operator *(float, Vector2);
	Vector2 normalise();
	float dot(Vector2&rhs);
	float distance(Vector2& rhs);
	operator float*();
};