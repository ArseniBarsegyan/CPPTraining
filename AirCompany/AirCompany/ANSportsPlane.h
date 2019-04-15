#pragma once
#include "SportsPlane.h"
#include <string>

class ANSportsPlane :
	public SportsPlane
{
private: 
	const int OnePassengerWeight = 90;
public:
	ANSportsPlane(string name, int speed, int fuelConsumption,
		int fuelCapacity, int crewNumber);
	~ANSportsPlane();

	string airDrop() {
		return "airdrop";
	}

	int getCarryingWeight() {
		return this->crewNumber * this->OnePassengerWeight;
	}

	float getFlyDistance() {
		return (this->speed * this->fuelCapacity / this->fuelConsumption) * 1000 / getCarryingWeight();
	}

	string getInfo() {
		return "Sports plane: " 
			+ this->name 
			+ ", speed: "
			+ std::to_string(this->speed)
			+ ", crew number: " 
			+ std::to_string(this->crewNumber)
			+ ", fuel consumption: " 
			+ std::to_string(this->fuelConsumption);
	}
};

ANSportsPlane::ANSportsPlane(string name, int speed, int fuelConsumption,
	int fuelCapacity, int crewNumber)
{
	this->name = name;
	this->speed = speed;
	this->fuelConsumption = fuelConsumption;
	this->fuelCapacity = fuelCapacity;
	this->crewNumber = crewNumber;
}

ANSportsPlane::~ANSportsPlane()
{
}