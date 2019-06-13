#pragma once
#include "port.h"
#include "station.h"

class rate;

class terminal
{
private:
	port* port_;
	station* station_;
public:
	terminal(port* port, station* station);
	rate* get_current_rate();
	void change_rate(rate* new_rate);
	void receive_call();
	std::string make_call(int number);
	void reject_call();
	void accept_call();
	void end_call();
	int get_balance();
	void add_money();
	~terminal();
	//TODO: turn off terminal - make port status inactive
	// stop_contract() - remove terminal and its port from lists.
};
