#pragma once
#include "rate.h"
#include "terminal.h"
#include "pch.h"

class company_subscriber
{	
private:
	rate* previous_rate_;
	rate* current_rate_;
	std::string name_;
	terminal* terminal_;
	int balance_;
	time_t creation_time_;
public:
	company_subscriber(std::string name, rate* prev_rate, 
		rate* cur_rate, terminal* terminal, int balance);
	void change_rate(rate* new_rate);
	void add_balance(int amount);
	~company_subscriber();
};
