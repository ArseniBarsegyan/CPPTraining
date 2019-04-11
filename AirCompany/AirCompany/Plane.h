#include <iostream>
#include <string>
using std::string;

#pragma once
class Plane
{
public:
	string name;
	int speed;
	int fuelConsumption;
	int fuelCapacity;
	virtual float getFlyDistance() = 0;
	virtual int getCarryingWeight() = 0;
	virtual string getInfo() = 0;
};

