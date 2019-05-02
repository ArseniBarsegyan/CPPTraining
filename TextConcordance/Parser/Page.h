#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

// Object model of page.
class Page
{
public:
	Page();
	Page(int current_page_number, int number_of_lines, vector<string> lines);
	~Page();

	// Add line of text to current page's lines
	void add_line(string line);
	int get_current_page_number();

	// Number of lines of current page
	int get_number_of_lines();

	// Get all lines with words
	vector<string> get_lines();
private:
	int current_page_number_;
	int number_of_lines_;
	vector<string> lines_;
};

