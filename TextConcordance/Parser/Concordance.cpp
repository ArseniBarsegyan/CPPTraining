#include "stdafx.h"
#include "Concordance.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using std::ofstream;
using std::map;
using std::vector;
using std::string;

Concordance::Concordance(vector<Word> words)
{
	this->words_ = words;
}

Concordance::~Concordance()
{
}

vector<string> Concordance::group_by_alpha_bet()
{
	vector<string> result_list;
	map<string, vector<Word>> words_group = create_groups(this->words_);

	for (auto i = words_group.begin(); i != words_group.end(); i++) {
		// transform group key to uppercase and add to result list
		string group_key = i->first;
		std::transform(group_key.begin(), group_key.end(), group_key.begin(), ::toupper);
		result_list.push_back(group_key);

		// get all words associated with key
		auto words = i->second;
		for (Word &word : words) {
			int repeat_count = word.get_repeat_count();
			string word_info = word.get_value() +
				" "
				+ std::to_string(repeat_count)
				+ ": ";

			for (auto page_number : *word.get_page_numbers()) {
				word_info.append(" ");
				word_info.append(std::to_string(page_number));
			}
			result_list.push_back(word_info);
		}
		auto value = i->second;
	}
	return result_list;
}

map<string, vector<Word>> Concordance::create_groups(vector<Word> words)
{
	map<string, vector<Word>> groups;

	for (Word &word : words) {
		auto word_beginning_letter = word.get_value().substr(0, 1);
		auto group = groups.find(word_beginning_letter);

		if (group != groups.end()) {
			// put word in group's words.
			groups[word_beginning_letter].push_back(word);
		}
		else {
			// create new group, add words collection and insert word to this collection.
			groups.insert(std::make_pair(word_beginning_letter, vector<Word>()));
			groups[word_beginning_letter].push_back(word);
		}
	}
	return groups;
}


void Concordance::WriteFile(string path)
{
	vector<string> concordance = group_by_alpha_bet();
	ofstream out(path);
	if (out.is_open()) {
		for (auto &line : concordance) {
			out << line << std::endl;
		}
	}
	out.close();
}
