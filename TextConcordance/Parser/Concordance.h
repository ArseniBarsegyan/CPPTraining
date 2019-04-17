#pragma once
#include <vector>
#include <string>
#include "Word.h"
using std::vector;
using std::string;

class Concordance
{
public:
	Concordance(vector<Word> words);
	~Concordance();

	void WriteFile(string path);
private:
	vector<Word> words;
	vector<string> GroupByAlphaBet();
};

