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
	this->closed_ports_->push_back(prt);
	return prt;
}

std::string station::make_call(port* from_port, int to_port_number)
{
	port* target_port = get_port_by_number(this->opened_ports_, to_port_number);
	if (target_port != nullptr)
	{
		target_port->establish_connection();
		// TODO - move port to busy list
		// fire event - port state changed. subscriber - terminal
		// when terminal will receive this event - it will ask user about confirmation
		// user reject call - send message to station. Station will notify 1st terminal that user is busy
		// and will move 2nd port to active status again.
		// if user accept call - set both ports to busy state, start writing time and send messages to both of users
		// after one of them end call - create new call object and save it.
		// company have access to calls list of the station.
		
		return "establishing call";
	}
	target_port = get_port_by_number(this->closed_ports_, to_port_number);
	if (target_port != nullptr)
	{
		return "user is offline";
	}
	target_port = get_port_by_number(this->busy_ports_, to_port_number);
	if (target_port != nullptr)
	{
		return "user is busy";
	}
	return "user doesn't exists";
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
