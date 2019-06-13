#include "port.h"

port::port(int number)
{
	this->number_ = number;
	this->status = "active";
}

int port::get_number()
{
	return this->number_;
}

port::~port()
{
}
