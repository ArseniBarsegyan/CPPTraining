#pragma once
#include "port.h"
#include "pch.h"

class rate;

class terminal
{
private:
	port* port_;
public:
	terminal(port* port_);
	rate* get_current_rate();
	void change_rate(rate* new_rate);
	void make_call(int number);
	void reject_call();
	void accept_call();
	int get_balance();
	void add_money();
	~terminal();
};
