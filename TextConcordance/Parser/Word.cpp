#include "stdafx.h"
#include "Word.h"

Word::Word(string value, int repeatCount, int numberOfPage, vector<int> pageNumbers)
{
	this->value = value;
	this->repeatCount = repeatCount;
	this->pageNumbers = pageNumbers;
	this->pageNumbers.push_back(numberOfPage);
}

Word::~Word()
{
}

void Word::IncreaseRepeatCount()
{
	this->repeatCount++;
}

string Word::GetValue()
{
	return this->value;
}

int Word::GetRepeatCount()
{
	return this->repeatCount;
}

vector<int> Word::GetPageNumbers()
{
	return this->pageNumbers;
}
