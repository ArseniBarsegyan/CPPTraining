#include "pch.h"
#include <iostream>
#include "Plane.h"
#include "ANSportsPlane.h"
#include "Company.h"

int main()
{
	Plane* sportsPlane = new ANSportsPlane("AN", 100, 10, 5000, 10);
	std::cout << sportsPlane;
}