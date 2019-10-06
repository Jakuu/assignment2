#ifndef DRIVINGSIMULATOR_SLEIGH_H
#define DRIVINGSIMULATOR_SLEIGH_H

#include "Vehicle.h"

class Sleigh : public Vehicle
{
private:
	//Number of reindeer pulling the sleigh
	int myReindeerCount;
public:
	//Must be at least one reindeer for the sleigh to move
	explicit Sleigh(string brand, string model, int reindeerCount = 1);

	virtual ~Sleigh();
	int getReindeerCount();
	void setReindeerCount(int deerCount);
	virtual double mileageEstimate(double time);

	virtual string toString();

};

#endif //DRIVINGSIMULATOR_SLEIGH_H