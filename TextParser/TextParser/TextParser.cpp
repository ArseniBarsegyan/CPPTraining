#include "pch.h"
#include <iostream>
#include "word.h"
#include "word_separator.h"
#include "sentence.h"
#include <chrono>

int main()
{
	// Measure app running time
	auto started = std::chrono::high_resolution_clock::now();

	// Managing these objects implemented in sentence class
	sentence_item* wrd_separator = new word_separator(new std::string("@"));
	sentence_item* wrd = new word(new std::string("test"));
	sentence_item* end_of_sentence = new word_separator(new std::string("?"));
	auto sentence_items = new std::vector<sentence_item*>();
	sentence_items->push_back(wrd);
	sentence_items->push_back(wrd_separator);
	sentence_items->push_back(end_of_sentence);
	auto sent = new sentence(sentence_items);

	sentence_item* replacement_word = new word(new std::string("replacement"));
	sentence_item* replacement_word2 = new word(new std::string("word"));
	sentence_item* replacement_separator = new word_separator(new std::string(" "));
	auto replacement_string = new std::vector<sentence_item*>();
	replacement_string->push_back(replacement_word);
	replacement_string->push_back(replacement_separator);
	replacement_string->push_back(replacement_word2);

	sent->replace_all_words_by_length_with_substring(4, replacement_string);
	delete replacement_string;
	replacement_string = nullptr;

	std::string sentence_value = sent->get_sentence();
	std::cout << sentence_value;
	std::cout << std::endl;	
	std::cout << sent->is_interrogative_sentence();
	std::cout << std::endl;

	auto unique_words = sent->get_all_unique_words(4);
	delete unique_words;
	unique_words = nullptr;

	sent->remove_all_sentence_words_start_with_consonant_by_length(4);
	std::string sentence_value_2 = sent->get_sentence();
	std::cout << sentence_value_2;
	std::cout << std::endl;
	
	delete sent;
	sent = nullptr;

	// Measure app running time
	auto done = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
}
