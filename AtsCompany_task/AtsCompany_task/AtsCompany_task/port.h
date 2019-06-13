#pragma once
#include <string>

class port
{
private:
	int number_;
public:
	port(int number);
	std::string status;
	int get_number();
	~port();
};
