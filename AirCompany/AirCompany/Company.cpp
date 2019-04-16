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
	int totalWeight = 0;
	for (unsigned i = 0; i < planes.size(); i++) {
		Plane* p = planes.at(i);
		totalWeight += p->getCarryingWeight();
	}
	return totalWeight;
}

bool comparePlanes(Plane *a, Plane *b) {
	return (a->getFlyDistance() > b->getFlyDistance());
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

