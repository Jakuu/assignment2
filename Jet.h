#ifndef DRIVINGSIMULATOR_JET_H
#define DRIVINGSIMULATOR_JET_H

#include "PoweredVehicle.h"

class Jet : public PoweredVehicle {

private:
	int numEngines;
	int randMileage;

public:
	Jet();

	explicit Jet(string brand, string model, string fuelType,
		int numberOfEngines);

	virtual ~Jet();
	int getNumberOfEngines();
	void setNumberOfEngines(int engines);
	virtual double mileageEstimate(double time);
	virtual string toString();
};


#endif //DRIVINGSIMULATOR_JET_H
