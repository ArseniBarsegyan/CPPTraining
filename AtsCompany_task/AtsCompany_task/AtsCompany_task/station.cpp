#include "station.h"

port* station::get_port_by_number(std::vector<port*>* ports, int to_port_number)
{
	port* target_port = nullptr;
	for (int i = 0; i < this->opened_ports_->size(); i++)
	{
		if (opened_ports_->at(i)->get_number() == to_port_number)
		{
			target_port = opened_ports_->at(i);
			break;
		}
	}
	return target_port;	
}

station::station()
{
	this->opened_ports_ = new std::vector<port*>();
	this->busy_ports_ = new std::vector<port*>();
	this->closed_ports_ = new std::vector<port*>();
}

port* station::create_new_port()
{
	int number = 11111111 + rand() % (99999999 - 11111111);
	port* prt = new port(number);
	return prt;
}

void station::make_call(port* from_port, int to_port_number)
{
	port* target_port = get_port_by_number(this->opened_ports_, to_port_number);
	if (target_port != nullptr)
	{
		// TODO: establish call
		return;
	}
	target_port = get_port_by_number(this->closed_ports_, to_port_number);
	if (target_port != nullptr)
	{
		// TODO: return answer: user is inactive
		return;
	}
	target_port = get_port_by_number(this->busy_ports_, to_port_number);
	if (target_port != nullptr)
	{
		// TODO: return answer: user is busy
		return;
	}
	// TODO: user not exists
}

station::~station()
{
	delete this->opened_ports_;
	delete this->busy_ports_;
	delete this->closed_ports_;

	this->opened_ports_ = nullptr;
	this->busy_ports_ = nullptr;
	this->closed_ports_ = nullptr;
}
