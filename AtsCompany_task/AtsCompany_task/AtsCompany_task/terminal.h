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
	void make_call(int number);
	void reject_call();
	void accept_call();
	int get_balance();
	void add_money();
	~terminal();
};
