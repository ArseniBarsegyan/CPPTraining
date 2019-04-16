#include "pch.h"
#include <iostream>
#include "Plane.h"
#include "ANSportsPlane.h"
#include "Company.h"
#include "Airbus.h";
#include "Boeing.h";
#include <time.h>

int main()
{
	clock_t t1, t2;
	t1 = clock();	

	//Creating collection of planes
	vector<Plane*> planes;
	planes.push_back(new Airbus("Airbus01", 900, 6000, 130000, 12000));
	planes.push_back(new Boeing("Boeing01", 1000, 5000, 120000, 400));
	planes.push_back(new ANSportsPlane("AN01", 300, 300, 600, 2));

	//Get info about every plane in list
	for (int i = 0; i < planes.size(); i++) {
		std::cout << planes.at(i)->getInfo()+"\n";
	}

	//Creating new company
	Company* airCompany = new Company("Airlines", planes);

	//Show all planes sorted by fly distance
	std::cout<< "--------------------\n";
	std::cout << "Sorted planes: \n";

	vector<Plane*> sortedPlanes = airCompany->sortPlanesByFlyingDistance();
	for (int i = 0; i < sortedPlanes.size(); i++) {
		std::cout << "Plane: " 
			+ sortedPlanes.at(i)->name
			+ ", distance: " 
			+ std::to_string(sortedPlanes.at(i)->getFlyDistance())<<"\n";
	}

	std::cout << "--------------------\n";

	//Show total capacity of the company and total carrying weight
	std::cout << "Info about company\n";

	std::cout << airCompany->name + " total capacity: " 
		+ std::to_string(airCompany->getTotalCapacity())
		+ ", total carrying weight: " 
		+ std::to_string(airCompany->getTotalCarryingWeight()) + "\n";
	std::cout << "--------------------\n";
	
	//Find all planes with fuel consumption between 0 and 1000 l/h
	std::cout << "Founded planes by fuel consumption between 0 and 1000:\n";
	vector<Plane*> planes2 = airCompany->findPlanesByFuelConsumption(0, 1000);

	for (int i = 0; i < planes2.size(); i++) {
		std::cout << planes2.at(i)->getInfo() + "\n";
	}

	//code goes here
	t2 = clock();

	float diff = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;
	std::cout << "Running time: " << diff;
	return 0;
}