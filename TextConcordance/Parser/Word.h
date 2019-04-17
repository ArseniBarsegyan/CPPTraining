#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;

class Word
{
public:
	Word(string value, int repeatCount, int numberOfPage, vector<int> pageNumbers);
	~Word();

	void IncreaseRepeatCount();
	string GetValue();
	int GetRepeatCount();
	vector<int> GetPageNumbers();
private: 
	string value;
	int repeatCount;
	vector<int> pageNumbers;
};

