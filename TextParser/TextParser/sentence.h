#pragma once
#include "sentence_item.h"
#include <vector>
#include "word.h"
#include <map>

class sentence
{
private:
	std::vector<sentence_item*>* sentence_items_;
	bool contains(std::string value, char symbol);
	std::map<std::string, std::vector<sentence_item*>*>* create_groups(std::vector<sentence_item*>* words);
public:
	sentence(std::vector<sentence_item*>* sentence_items);
	std::vector<sentence_item*>* get_sentence_items();
	int get_word_count();
	bool is_interrogative_sentence();
	std::vector<sentence_item*>* get_all_unique_words(int length);
	void replace_all_words_by_length_with_substring(unsigned long word_length, std::vector<sentence_item*>* items);
	void remove_all_sentence_words_start_with_consonant_by_length(int length);
	std::string get_sentence();
	~sentence();
};
