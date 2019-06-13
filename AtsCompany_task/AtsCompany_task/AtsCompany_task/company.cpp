#include "company.h"

void company::initialize_rates()
{
	rate* super_rate = new rate(10, "super-rate");
	this->available_rates_->push_back(super_rate);
}

company::company()
{
	this->subscriber_initial_balance = 100;
	this->station_ = new station();
	this->subscribers_ = new std::vector<company_subscriber*>();
	this->available_rates_ = new std::vector<rate*>();
	this->all_terminals_ = new std::vector<terminal*>();
	initialize_rates();
}

void company::change_rate(rate* new_rate, company_subscriber* subscriber)
{
	subscriber->change_rate(new_rate);
}

terminal* company::create_subscriber(std::string name)
{
	auto new_terminal = new terminal(this->station_->create_new_port(), station_);
	this->all_terminals_->push_back(new_terminal);
	auto initial_rate = this->available_rates_->at(0);

	company_subscriber* subscriber = new company_subscriber(name, initial_rate,
		initial_rate, 
		new_terminal, 
		this->subscriber_initial_balance);
	this->subscribers_->push_back(subscriber);
	return new_terminal;
}

void company::add_money(int amount, company_subscriber* subscriber)
{
	subscriber->add_balance(amount);
}

company::~company()
{
	delete this->station_;
	this->station_ = nullptr;

	delete this->available_rates_;
	this->available_rates_ = nullptr;

	delete this->subscribers_;
	this->subscribers_ = nullptr;

	delete this->all_terminals_;
	this->all_terminals_ = nullptr;
}
