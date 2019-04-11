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

	void addPlane(Plane* plane) {
		planes.push_back(plane);
	}

	void removePlane(Plane* plane) {
		for (unsigned i = 0; i < planes.size(); i++) {
			if (planes.at(i) == plane) {
				planes.erase(planes.begin() + i);
			}
		}
	}

	int getTotalCapacity() {
		return planes.size();
	}

	int getTotalCarryingWeight() {
	}

	bool comparePlanes(Plane *a, Plane *b) {
		return (a->fuelConsumption - b->fuelConsumption);
	}

	vector<Plane*> sortPlanesByFlyingDistance() {
		
		std::sort(planes.begin(), planes.end(), comparePlanes);
	}

	vector<Plane*> findPlanesByFuelConsumption(int startValue, int endValue) {
		vector<Plane*> founded;
		for (int i = 0; i < planes.size(); i++) {
			if (planes.at(i)->fuelConsumption >= startValue && planes.at(i)->fuelConsumption <= endValue) {
				founded.push_back(planes.at(i));
			}
		}
		return founded;
	}

	int compare(const void * x1, const void * x2)
	{
		auto p1 = (Plane*)x1;
		auto p2 = (Plane*)x2;
		return (int)(p1->getFlyDistance - p2->getFlyDistance());
	}
};