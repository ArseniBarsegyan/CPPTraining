#pragma once
#include "sentence_item.h"

class sentence_separator : public sentence_item
{
private:
	std::string* value_;
public:
	sentence_separator(std::string* value);
	std::string* get_value() override;
	~sentence_separator();
};
