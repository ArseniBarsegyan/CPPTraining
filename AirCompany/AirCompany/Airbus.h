#pragma once
#include "CargoPlane.h"
#include <string>
class Airbus :
	public CargoPlane
{
public:
	Airbus(string name, int speed, int fuelConsumption, 
		int fuelCapacity, int carryingCapacity);
	~Airbus();

	int getCarryingWeight() {
		return this->carryingCapacity;
	}

	float getFlyDistance() {
		return (this->speed * this->fuelCapacity / this->fuelConsumption) * 1000 / getCarryingWeight();
	}

	string getInfo() {
		return "Cargo plane: "
			+ this->name 
			+ ", speed: " 
			+ std::to_string(this->speed)
			+ ", carrying weight: " 
			+ std::to_string(getCarryingWeight()) 
			+ ", fuel consumption: "
			+ std::to_string(fuelConsumption);
	}
};

Airbus::Airbus(string name, int speed, int fuelConsumption,
	int fuelCapacity, int carryingCapacity)
{
	this->name = name;
	this->speed = speed;
	this->fuelConsumption = fuelConsumption;
	this->fuelCapacity = fuelCapacity;
	this->carryingCapacity = carryingCapacity;
}


Airbus::~Airbus()
{
}
