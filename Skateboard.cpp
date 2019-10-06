#include "Skateboard.h"
//Includes for random functionality
//includes and usage taken from cplusplus.com/reference/cstdlib/rand/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Include for floor function
#include<cmath>

Skateboard::Skateboard(string brand, string model)
{
	setBrand(brand);
	setModel(model);
	//Seed random for generation in mileageEstimate function
	srand(time(0));
}

Skateboard::~Skateboard() = default;

double Skateboard::mileageEstimate(double time)
{
	double genRand = (rand() % 5 + 1) / 10;
	double mileage = genRand * time;
	if (time > 25 && time < 250)
	{
		genRand = rand() % (floor(time / 3)) + 1;
		mileage += genRand;
	}
	return mileage;
}

string Skateboard::toString()
{
	return "-> Skateboard\n" + Vehicle::toString();
}