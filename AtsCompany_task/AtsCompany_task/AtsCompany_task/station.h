#pragma once
#include "port.h"
#include <vector>

class station
{
private:
	std::vector<port*>* closed_ports_;
	std::vector<port*>* opened_ports_;
	std::vector<port*>* busy_ports_;

	port* get_port_by_number(std::vector<port*>* ports, int to_port_number);
public:
	station();
	port* create_new_port();
	std::string make_call(port* from_port, int to_port_number);
	~station();
};
