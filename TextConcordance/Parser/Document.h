#pragma once
#include "Page.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Document
{
public:
	Document(string name, vector<Page> pages);
	~Document();

	string GetName();
	vector<Page> GetPages();
private:
	string name;
	vector<Page> pages;
};

