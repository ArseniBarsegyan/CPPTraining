#pragma once
#include <string>

class rate
{
public:
	rate(int cost_per_minute, std::string name);
	int cost_per_minute;
	std::string name;
};
