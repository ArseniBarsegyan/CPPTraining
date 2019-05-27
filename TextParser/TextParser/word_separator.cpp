#include "pch.h"
#include "word_separator.h"

word_separator::word_separator(std::string* value)
{
	this->value_ = value;
}

std::string* word_separator::get_value()
{
	return this->value_;
}

word_separator::~word_separator()
{
	delete this->value_;
}
