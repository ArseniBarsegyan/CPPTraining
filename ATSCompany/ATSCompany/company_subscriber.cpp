#include "pch.h"
#include "company_subscriber.h"
#include <chrono>

company_subscriber::company_subscriber(std::string name, rate* prev_rate, 
	rate* cur_rate, 
	terminal* terminal,
	int balance)
{
	this->name_ = name;
	this->previous_rate_ = prev_rate;
	this->current_rate_ = cur_rate;
	this->terminal_ = terminal;
	this->balance_ = balance;

	auto current_time = std::chrono::system_clock::now();
	this->creation_time_ = std::chrono::system_clock::to_time_t(current_time);
}

// TODO: check that subscriber can change rate only once per month
void company_subscriber::change_rate(rate* new_rate)
{
	auto current_time = std::chrono::system_clock::now();
	this->creation_time_ = std::chrono::system_clock::to_time_t(current_time);
	/*auto creation_time = std::chrono::system_clock::from_time_t(this->creation_time_);

	using hours =
		std::chrono::duration<long, std::ratio_multiply<std::ratio<60>, std::chrono::minutes::period>>;

	std::chrono::duration<hours> elapsed_hours = current_time - creation_time;*/

	this->previous_rate_ = this->current_rate_;
	this->current_rate_ = new_rate;
}

void company_subscriber::add_balance(int amount)
{
	this->balance_ += amount;
}

company_subscriber::~company_subscriber()
{
}
