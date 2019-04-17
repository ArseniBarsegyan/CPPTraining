#include "stdafx.h"
#include "Page.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

Page::Page() {}

Page::Page(int currentPageNumber, int numberOfLines, vector<string> lines)
{
	this->currentPageNumber = currentPageNumber;
	this->numberOfLines = numberOfLines;
	this->lines = lines;
}

Page::~Page()
{
}

void Page::AddLine(string line)
{
	this->lines.push_back(line);
}

int Page::GetCurrentPageNumber()
{
	return this->currentPageNumber;
}

int Page::GetNumberOfLines()
{
	return this->numberOfLines;
}

vector<string> Page::GetLines()
{
	return this->lines;
}
