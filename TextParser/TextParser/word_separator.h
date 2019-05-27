#pragma once
#include <string>
#include "sentence_item.h"

class word_separator : public sentence_item
{
private:
	std::string* value_;
public:
	word_separator(std::string* value);
	std::string* get_value() override;
	~word_separator();
};
