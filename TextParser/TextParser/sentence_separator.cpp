#include "pch.h"
#include "sentence_separator.h"

sentence_separator::sentence_separator(std::string* value)
{
	this->value_ = value;
}

std::string sentence_separator::get_value()
{
	return *this->value_;
}

sentence_separator::~sentence_separator()
{
	delete this->value_;
	value_ = nullptr;
}
