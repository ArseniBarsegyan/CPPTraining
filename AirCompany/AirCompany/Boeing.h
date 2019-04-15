#pragma once
#include "PassengerPlane.h"
#include <string>
class Boeing :
	public PassengerPlane
{
private:
	const int OnePassengerWeight = 80;
public:
	Boeing(string name, int speed, int fuelConsumption, 
		int fuelCapacity, int passengersNumber);
	~Boeing();

	int getCarryingWeight() {
		return this->passengersNumber * OnePassengerWeight;
	}

	float getFlyDistance() {
		return (this->speed * this->fuelCapacity / this->fuelConsumption) * 1000 / getCarryingWeight();
	}

	string getInfo() {
		return "Passenger plane: " 
			+ this->name
			+ ", speed: "
			+ std::to_string(this->speed)
			+ ", passengers number: " 
			+ std::to_string(this->passengersNumber) 
			+ ", fuel consumption: "
			+ std::to_string(this->fuelConsumption);
	}
};

Boeing::Boeing(string name, int speed, int fuelConsumption, 
	int fuelCapacity, int passengersNumber)
{
	this->name = name;
	this->speed = speed;
	this->fuelConsumption = fuelConsumption;
	this->fuelCapacity = fuelCapacity;
	this->passengersNumber = passengersNumber;
}


Boeing::~Boeing()
{
}
