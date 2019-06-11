#pragma once
#include <string>
#include "sentence_item.h"

class word : public sentence_item
{
private:
	std::string* value_;
public:
	word(std::string* value);
	std::string get_value() override;
	void add_symbol(char* c);
	~word();
};
