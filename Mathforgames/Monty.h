#pragma once
#include <cstdlib>
#include<time.h>
class Monty
{
public:
	Monty();
	int selection;
	int correct;
	int other;
	int keptC;
	int keptW;
	int switchC;
	int switchW;
	bool didSwitch;
	bool didKeep;

	int chooseCorrect(int);
	int chooseSelect(int);
	int chooseOther(int);
	bool switchChoice();
	void checkAns();
	float chanceSwitch();
	float chanceKept();
};