#pragma once
#include "port.h"
#include <vector>
#include "pch.h"

class station
{
private:
	std::vector<port*> closed_ports_;
	std::vector<port*> opened_ports_;
	std::vector<port*> busy_ports_;
public:
	port* create_new_port();
	void make_call(int port_number);
};
