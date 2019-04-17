#include "stdafx.h"
#include "Document.h"
#include "Page.h"
#include <vector>
#include <string>
using std::vector;
using std::string;


Document::Document(string name, vector<Page> pages)
{
	this->name = name;
	this->pages = pages;
}

Document::~Document()
{
}

string Document::GetName()
{
	return this->name;
}

vector<Page> Document::GetPages()
{
	return this->pages;
}
