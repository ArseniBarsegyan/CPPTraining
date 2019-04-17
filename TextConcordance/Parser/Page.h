#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class Page
{
public:
	Page();
	Page(int currentPageNumber, int numberOfLines, vector<string> lines);
	~Page();

	void AddLine(string line);
	int GetCurrentPageNumber();
	int GetNumberOfLines();
	vector<string> GetLines();
private:
	int currentPageNumber;
	int numberOfLines;
	vector<string> lines;
};

