#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;

class Word
{
public:
	Word(string value, int repeat_count, int number_of_page, vector<int> page_numbers);
	~Word();

	void increase_repeat_count();
	string get_value();
	int get_repeat_count();
	vector<int> get_page_numbers();
private: 
	string value_;
	int repeat_count_;
	vector<int> page_numbers_;
};

