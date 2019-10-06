#include "Jet.h"
//Includes for random functionality
//includes and usage taken from cplusplus.com/reference/cstdlib/rand/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Jet::Jet()
{
	numEngines = 1;
	setBrand("Custom");
	//Assigning a Jet model for default constructor as done in Car.cpp
	setModel("F16");
	//Assuming the random mileage per unit time is constant per jet, but random
	//Between jets
	srand(time(0));
	randMileage = rand() % 61 + 40;
}

Jet::Jet(string brand, string model, string fuelType,
	int numberOfEngines)
{
	setBrand(brand);
	setModel(model);
	setFuelType(fuelType);
	setNumberOfEngines(numberOfEngines);
	//Assuming the random mileage per unit time is constant per jet, but random
	//Between jets
	srand(time(0));
	//Generate random integer between 40 and 100
	randMileage = rand() % 61 + 40;
}

Jet::~Jet() = default;

int Jet::getNumberOfEngines()
{
	return numEngines;
}

void Jet::setNumberOfEngines(int engines)
{
	//Jet must have at least 1 engine
	if (engines > 0)
		numEngines = engines;
}

double Jet::mileageEstimate(double time)
{
	//Use pre-generated randMileage variable
	double mileage = time * randMileage;
	//Increase mileage if rocket fuel and >2 engines
	if (fuelType == "Rocket" && numEngines > 2)
		mileage += mileage * (0.055 * numEngines);
	return mileage;
}

string Jet::toString()
{
	return "-> Jet\n" + PoweredVehicle::toString() + "\n\tNumber of Engines: " + to_string(getNumberOfEngines());
}