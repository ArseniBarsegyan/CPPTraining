#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class Page
{
public:
	Page();
	Page(int current_page_number, int number_of_lines, vector<string> lines);
	~Page();

	void add_line(string line);
	int get_current_page_number();
	int get_number_of_lines();
	vector<string> get_lines();
private:
	int current_page_number_;
	int number_of_lines_;
	vector<string> lines_;
};

