#include "pch.h"
#include "Company.h"
#include <algorithm>

Company::Company(string name, std::vector<Plane*> planes)
{
	this->name = name;
	this->planes = planes;
}


Company::~Company()
{
}

void Company::addPlane(Plane* plane) {
	planes.push_back(plane);
}

void Company::removePlane(Plane* plane) {
	for (unsigned i = 0; i < planes.size(); i++) {
		if (planes.at(i) == plane) {
			planes.erase(planes.begin() + i);
		}
	}
}

int Company::getTotalCapacity() {
	return planes.size();
}

int Company::getTotalCarryingWeight()
{
	return 0;
}

bool comparePlanes(Plane *a, Plane *b) {
	return (a->fuelConsumption - b->fuelConsumption);
}

vector<Plane*> Company::sortPlanesByFlyingDistance() {
	std::sort(planes.begin(), planes.end(), comparePlanes);
	return planes;
}

vector<Plane*> Company::findPlanesByFuelConsumption(int startValue, int endValue) {
	vector<Plane*> founded;
	for (int i = 0; i < planes.size(); i++) {
		if (planes.at(i)->fuelConsumption >= startValue && planes.at(i)->fuelConsumption <= endValue) {
			founded.push_back(planes.at(i));
		}
	}
	return founded;
}

