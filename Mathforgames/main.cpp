#include "Matrix3.h"
#include "Monty.h"

int main()
{
	Matrix3 test1(1,0,0,0,1,0,0,0,1);
	Matrix3 test2(1,0,5,0,1,5,0,0,1);
	Vector3 test4(1, 5, 5);
	Matrix3 test3 = test1 * test2;
	Vector3 test5 = test3 * test4;
	Monty gameshow;
	gameshow.chooseCorrect(2);
	gameshow.chooseSelect(2);
	gameshow.
}
