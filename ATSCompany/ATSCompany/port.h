#pragma once
#include <string>
#include "pch.h"

class port
{
private:
	int number_;
public:
	port(int number);
	std::string status;
	~port();
};
