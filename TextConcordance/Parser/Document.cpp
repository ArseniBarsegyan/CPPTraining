#include "stdafx.h"
#include "Document.h"
#include "Page.h"
#include <vector>
#include <string>
using std::vector;
using std::string;


Document::Document(string name, vector<Page> pages)
{
	this->name_ = name;
	this->pages_ = pages;
}

Document::~Document()
{
}

string Document::get_name()
{
	return this->name_;
}

vector<Page> Document::get_pages()
{
	return this->pages_;
}
