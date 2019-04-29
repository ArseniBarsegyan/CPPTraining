#include "stdafx.h"
#include "Page.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

Page::Page() {}

Page::Page(int current_page_number, int number_of_lines, vector<string> lines)
{
	this->current_page_number_ = current_page_number;
	this->number_of_lines_ = number_of_lines;
	this->lines_ = lines;
}

Page::~Page()
{
}

void Page::add_line(string line)
{
	this->lines_.push_back(line);
}

int Page::get_current_page_number()
{
	return this->current_page_number_;
}

int Page::get_number_of_lines()
{
	return this->number_of_lines_;
}

vector<string> Page::get_lines()
{
	return this->lines_;
}
