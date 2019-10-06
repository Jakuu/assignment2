#include "Sleigh.h"
//Includes for random functionality
//includes and usage taken from cplusplus.com/reference/cstdlib/rand/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Sleigh::Sleigh(string brand, string model, int reindeerCount)
{
	setBrand(brand);
	setModel(model);
	setReindeerCount(reindeerCount);
	//Seed random for mileage calculation
	srand(time(0));
}

Sleigh::~Sleigh() = default;

int Sleigh::getReindeerCount()
{
	return myReindeerCount;
}

void Sleigh::setReindeerCount(int deerCount)
{
	//Sleigh must have at least 1 deer
	if (deerCount > 0)
		myReindeerCount = deerCount;
}

double Sleigh::mileageEstimate(double time)
{
	//Base mileage of 50 miles per deer, per unit time
	double mileage = (50 * myReindeerCount) * time;
	//If more than 3 deer, approach maximum deer strength efficiency
	if (myReindeerCount > 3)
	{
		mileage += mileage * (1.5 * myReindeerCount);
	}
	//Roll a 20 sided die, if you roll a 20, this is Santa's sleigh and moves much faster
	if ((rand() % 20 + 1) == 20)
	{
		mileage = mileage * 100;
	}

	return mileage;
	
}

string Sleigh::toString()
{
	return "-> Sleigh\n" + Vehicle::toString() + "\n\tReindeer: " +
		to_string(myReindeerCount);
}
