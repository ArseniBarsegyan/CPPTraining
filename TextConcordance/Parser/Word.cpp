#include "stdafx.h"
#include "Word.h"

Word::Word(string value, int repeat_count, int number_of_page, vector<int> page_numbers)
{
	this->value_ = value;
	this->repeat_count_ = repeat_count;
	this->page_numbers_ = page_numbers;
	this->page_numbers_.push_back(number_of_page);
}

Word::~Word()
{
}

void Word::increase_repeat_count()
{
	this->repeat_count_++;
}

string Word::get_value()
{
	return this->value_;
}

int Word::get_repeat_count()
{
	return this->repeat_count_;
}

vector<int> Word::get_page_numbers()
{
	return this->page_numbers_;
}
