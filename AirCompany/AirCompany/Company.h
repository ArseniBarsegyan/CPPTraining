#include "Plane.h"
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

#pragma once
class Company {
private: 
	vector<Plane*> planes;
public: 
	string name;
	void addPlane(Plane* plane);
	void removePlane(Plane* plane);
	int getTotalCapacity();
	int getTotalCarryingWeight();
	vector<Plane*> sortPlanesByFlyingDistance();
	vector<Plane*> findPlanesByFuelConsumption(int startValue, int endValue);	
};