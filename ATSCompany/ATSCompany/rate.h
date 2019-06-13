#pragma once
#include <string>
#include "pch.h"

class rate
{
public:
	rate(int cost_per_minute, std::string name);
	int cost_per_minute;
	std::string name;
};
