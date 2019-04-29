#pragma once
#include <vector>
#include <string>
#include <map>
#include "Word.h"
using std::vector;
using std::string;
using std::map;

class Concordance
{
public:
	Concordance(vector<Word> words);
	~Concordance();

	void WriteFile(string path);
private:
	vector<Word> words_;
	vector<string> group_by_alpha_bet();
	map<string, vector<Word>> create_groups(vector<Word> words);
};

