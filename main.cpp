#include <iostream>
#include "Car.h"
#include "Bicycle.h"
#include "Jet.h"
#include "Sleigh.h"

void printVehiclesRoster(Vehicle **vehicles, int size);

int main() {
    std::cout << "Driving simulator" << std::endl;
    int size = 10;
    int capacity = 10;
    Vehicle **vehiclesArray = new Vehicle *[capacity];

    vehiclesArray[0] = new Car();
    vehiclesArray[1] = new Bicycle("eTAP", "P5X");
    vehiclesArray[2] = new Bicycle("R&A", "Dogma F8", 5);
    vehiclesArray[3] = new Car("Tesla", "T2", "electricity", "large");
    vehiclesArray[4] = new Bicycle("Mizuno", "Wave", 10);
    vehiclesArray[5] = new Car("BMW", "X5", "diesel", "grande");
	//Test default constructor for Jet
	vehiclesArray[6] = new Jet();
	//Test parameterized Jet constructor
	vehiclesArray[7] = new Jet("US Air Force", "Scary Plane", "Rocket");
	//Test deer constructor with enough deer to hit peak efficiency
	vehiclesArray[8] = new Sleigh("NorthPoleSleds", "ReindeerTurbo", "8");
	//Test deer constructor with invalid deer count
	vehiclesArray[9] = new Sleigh("BadSleds", "SlowSleighs", "0");

	testConstructorValidation(vehiclesArray);

    printVehiclesRoster(vehiclesArray, size);

    if (vehiclesArray != 0) { // If it is not a null pointer
        // do not use nullptr. It is not supported on linprog
        for (int i = 0; i < size; i++) {
            delete vehiclesArray[i];
        }
        delete[] vehiclesArray;
    }
    return 0;
}

void testConstructorValidation(Vehicle** vehiclesArray)
{
	double dist = 5;
	cout << "\nShould return 8 deer: " + vehiclesArray[8]->mileageEstimate(dist) << endl;
	cout << "\nShould reutrn 1 deer: " + vehiclesArray[9]->mileageEstimate(dist) << endl;

}


void printVehiclesRoster(Vehicle **vehicles, int size) {
    double simulatedDistance = 130;
    for (int i = 0; i < size; i++) {
        cout << i << " " << vehicles[i]->toString() << endl;
        cout << "\tWould travel: "
             << vehicles[i]->mileageEstimate(simulatedDistance) << " miles in "
             << simulatedDistance << " seconds" << endl;
    }
}