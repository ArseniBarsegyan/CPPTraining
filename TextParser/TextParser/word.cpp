#include "pch.h"
#include "word.h"

word::word(std::string* value)
{
	this->value_ = value;
}

std::string* word::get_value()
{
	return this->value_;
}

void word::add_symbol(char* c)
{
	this->value_->append(c);
}

word::~word()
{
	delete this->value_;
}

