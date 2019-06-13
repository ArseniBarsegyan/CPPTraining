#include "call.h"

call::call(std::string status, port* port_1, port* port_2, rate* current_rate)
{
	this->status_ = status;
	this->port_1_ = port_1;
	this->port_2_ = port_2;
	this->current_rate_ = current_rate;
}

int call::get_duration()
{
	return this->duration_;
}

std::string call::get_status()
{
	return this->status_;
}

port* call::get_port_1()
{
	return this->port_1_;
}

port* call::get_port_2()
{
	return this->port_2_;
}

rate* call::get_current_rate()
{
	return this->current_rate_;
}

call::~call()
{
	this->port_1_ = nullptr;
	this->port_2_ = nullptr;
	this->current_rate_ = nullptr;
}
