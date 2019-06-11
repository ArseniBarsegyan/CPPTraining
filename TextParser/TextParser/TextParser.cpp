#include "pch.h"
#include <iostream>
#include "word.h"
#include "word_separator.h"
#include "sentence.h"

int main()
{
	// Managing these objects implemented in sentence class
	sentence_item* wrd_separator = new word_separator(new std::string("@"));
	sentence_item* wrd = new word(new std::string("test"));
	auto sentence_items = new std::vector<sentence_item*>();
	sentence_items->push_back(wrd);
	sentence_items->push_back(wrd_separator);
	auto sent = new sentence(sentence_items);

	sentence_item* replacement_word = new word(new std::string("replacement"));
	sentence_item* replacement_word2 = new word(new std::string("word"));
	sentence_item* replacement_separator = new word_separator(new std::string(" "));
	auto replacement_string = new std::vector<sentence_item*>();
	replacement_string->push_back(replacement_word);
	replacement_string->push_back(replacement_separator);
	replacement_string->push_back(replacement_word2);

	sent->replace_all_words_by_length_with_substring(4, replacement_string);

	std::cout << *sent->get_sentence();
	delete sent;
	sent = nullptr;
}
