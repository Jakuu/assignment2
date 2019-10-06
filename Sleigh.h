#ifndef DRIVINGSIMULATOR_SLEIGH_H
#define DRIVINGSIMULATOR_SLEIGH_H

#include "Vehicle.h"

class Sleigh : public Vehicle
{
private:
	int myReindeerCount;
public:
	explicit Sleigh(string brand, string model, int reindeerCount = 1);

	virtual ~Sleigh();
	int getReindeerCount();
	void setReindeerCount(int deerCount);
	virtual double mileageEstimate(double time);

	virtual string toString();

};

#endif //DRIVINGSIMULATOR_SLEIGH_H