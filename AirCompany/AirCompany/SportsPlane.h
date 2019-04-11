#include "Plane.h"

#pragma once
class SportsPlane : public Plane
{
public:
	int carryingCapacity;
	virtual std::string airDrop() = 0;
};