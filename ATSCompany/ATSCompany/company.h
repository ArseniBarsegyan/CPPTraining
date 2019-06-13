#pragma once
#include <vector>
#include "station.h"
#include "company_subscriber.h"
#include "pch.h"

class company
{
private:
	int subscriber_initial_balance;
	station* station_;
	std::vector<rate*>* available_rates_;
	std::vector<company_subscriber*>* subscribers_;
	std::vector<terminal*>* all_terminals_;

	void initialize_rates();
public:
	company();
	void change_rate(rate* new_rate, company_subscriber* subscriber);
	company_subscriber* create_subscriber(std::string name);
	void add_money(int amount, company_subscriber* subscriber);
	~company();
};
