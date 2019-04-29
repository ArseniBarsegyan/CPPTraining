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

	string get_name();
	vector<Page> get_pages();
private:
	string name_;
	vector<Page> pages_;
};

