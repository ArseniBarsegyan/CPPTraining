#include "pch.h"
#include <iostream>
#include "word.h"
#include "word_separator.h"
#include "sentence.h"

int main()
{
	sentence_item* wrd_separator = new word_separator(new std::string("@"));
	sentence_item* wrd = new word(new std::string("test"));
	auto sentence_items = new std::vector<sentence_item*>();
	sentence_items->push_back(wrd);
	sentence_items->push_back(wrd_separator);
	auto sent = new sentence(sentence_items);
	std::cout << *sent->get_sentence();
	delete sent;
}
