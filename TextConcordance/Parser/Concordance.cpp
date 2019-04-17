#include "stdafx.h"
#include "Concordance.h"
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
using std::ofstream;
using std::map;

Concordance::Concordance(vector<Word> words)
{
	this->words = words;
}

Concordance::~Concordance()
{
}

bool compareWords(Word a, Word b) {
	return (a.GetValue().compare(b.GetValue()));
}

vector<string> Concordance::GroupByAlphaBet()
{
	vector<string> resultList;
	vector<Word> orderedWords = this->words;
	std::sort(orderedWords.begin(), orderedWords.end(), compareWords);

	map<string, vector<Word>> wordsGroup = CreateGroups(orderedWords);

	for (auto i = wordsGroup.begin(); i != wordsGroup.end(); i++) {
		// transform group key to uppercase and add to result list
		string groupKey = i->first;
		std::transform(groupKey.begin(), groupKey.end(), groupKey.begin(), ::toupper);
		resultList.push_back(groupKey);

		// get all words associated with key
		auto words = i->second;
		for (auto j = 0; j < words.size(); j++) {
			auto word = words.at(j);

			string wordInfo = word.GetValue() + 
				" " 
				+ std::to_string(word.GetRepeatCount())
				+ ": ";

			for (int k = 0; k < word.GetPageNumbers().size(); k++) {
				wordInfo.append(" ");
				wordInfo.append(std::to_string(word.GetPageNumbers()[k]));
			}
			resultList.push_back(wordInfo);
		}

		auto value = i->second;
	}
	return resultList;
}

map<string, vector<Word>> CreateGroups(vector<Word> words) {
	map<string, vector<Word>> groups;

	for (int i = 0; i < words.size(); i++) {
		auto wordBeginningLetter = words[i].GetValue().substr(0, 1);
		auto group = groups.find(wordBeginningLetter);
		
		if (group != groups.end()) {
			// put word in group's words.
			groups[wordBeginningLetter].push_back(words[i]);
		}
		else {
			// create new group, add words collection and insert word to this collection.
			groups.insert(std::make_pair(wordBeginningLetter, vector<Word>()));
			groups[wordBeginningLetter].push_back(words[i]);
		}
	}
}

void Concordance::WriteFile(string path)
{
	vector<string> concordance = GroupByAlphaBet();
	ofstream out(path);
	if (out.is_open) {
		for (int i = 0; i < concordance.size(); i++) {
			out << concordance[i] << std::endl;
		}
	}
	out.close();
}