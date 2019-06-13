#pragma once
#include <string>
#include "port.h"
#include "rate.h"
#include "pch.h"

class call
{
private:
	std::string status_;
	port* port_1_;
	port* port_2_;
	rate* current_rate_;
	int duration_;
public:
	call(std::string status, port* port_1, port* port_2, rate* current_rate);	
	int get_duration();
	std::string get_status();
	port* get_port_1();
	port* get_port_2();
	rate* get_current_rate();
	~call();
};
