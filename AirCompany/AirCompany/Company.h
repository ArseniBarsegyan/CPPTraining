#pragma once
#include "Plane.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Company
{
private:
	vector<Plane*> planes;
public:
	Company();
	~Company();
	string name;
	void addPlane(Plane* plane);
	void removePlane(Plane* plane);
	int getTotalCapacity();
	int getTotalCarryingWeight();
	vector<Plane*> sortPlanesByFlyingDistance();
	vector<Plane*> findPlanesByFuelConsumption(int startValue, int endValue);
};

