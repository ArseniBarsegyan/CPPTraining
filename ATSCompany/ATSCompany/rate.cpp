#include "pch.h"
#include "rate.h"

rate::rate(int cost_per_minute, std::string name)
{
	this->cost_per_minute = cost_per_minute;
	this->name = name;
}
