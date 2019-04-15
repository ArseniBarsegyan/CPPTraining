#include "Plane.h"

#pragma once
class SportsPlane : public Plane
{
public:
	int crewNumber;
	virtual std::string airDrop() = 0;
};