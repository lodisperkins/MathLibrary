#include "Monty.h"

int Monty::chooseCorrect(int num)
{
	srand(time(NULL));
	return correct = rand() % num;
}

int Monty::chooseSelect(int choice)
{
	srand(time(NULL));
	return selection = rand() % choice;
}

int Monty::chooseOther(int num)
{
	
}

bool Monty::switchChoice()
{
	srand(time(NULL));
	int decision = rand() % 1;
	if (decision == 1)
	{
		int temp = other;
		other = selection;
		selection = temp;
		return true;
	}
	else
	{
		return false;
	}
	
}

void Monty::checkAns()
{
	if (selection == correct && didSwitch == true)
	{
		switchC++;
	}
	else if (selection == correct && didKeep == true)
	{
		keptC++;
	}
	else if (selection !=correct&& didSwitch == true)
	{
		switchW++;
	}
	else if (selection != correct && didKeep == true)
	{
		keptW++;
	}
}

float Monty::chanceSwitch()
{
	return switchC/(switchC+switchW);
}

float Monty::chanceKept()
{
	return switchC / (switchC + switchW);
}
