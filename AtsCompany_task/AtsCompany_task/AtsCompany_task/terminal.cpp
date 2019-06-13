#include "terminal.h"
#include <iostream>

terminal::terminal(port* port, station* station)
{
	this->port_ = port;
	this->station_ = station;
}

void terminal::receive_call()
{
	std::cout << "accept call?";
}

void terminal::make_call(int number)
{
	this->station_->make_call(this->port_, number);
}
