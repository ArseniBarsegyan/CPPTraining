#include "pch.h"
#include "sentence.h"
#include <typeinfo>

sentence::sentence(std::vector<sentence_item*>* sentence_items)
{
	this->sentence_items_ = sentence_items;
}

std::vector<sentence_item*>* sentence::get_sentence_items()
{
	return this->sentence_items_;
}

int sentence::get_word_count()
{
	int count = 0;
	for (auto& item : *sentence_items_)
	{
		const std::type_info& type_info = typeid(*item);
		if (type_info == typeid(word))
		{
			count++;
		}
	}
	return count;
}

bool sentence::contains(std::string* value, char symbol)
{
	bool contains = false;
	for (auto& letter : *value)
	{
		if (letter == symbol)
		{
			contains = true;
		}
	}
	return contains;
}

bool sentence::is_interrogative_sentence()
{
	for (auto& item : *sentence_items_)
	{
		if (contains(item->get_value(), '?'))
		{
			return true;
		}
	}
	return false;
}

std::vector<word*>* sentence::get_all_unique_words(int length)
{
	std::vector<word*>* words = new std::vector<word*>();
	return words;
}

// TODO: check this method work
void sentence::replace_all_words_by_length_with_substring(unsigned long word_length, std::vector<sentence_item*>* items)
{
	for (auto i = 0; i < sentence_items_->size(); ++i)
	{
		auto& item = *sentence_items_->at(i);
		const std::type_info& type_info = typeid(item);
		if (type_info != typeid(word))
		{
			continue;
		}
		if (item.get_value()->size() != word_length)
		{
			continue;
		}

		// delete object from RAM and set it's pointer to null
		sentence_items_->at(i) = nullptr;
		delete& item;
		
		auto current_position = i;
		for (auto &subItem : *items)
		{
			auto iter = sentence_items_->begin();
			sentence_items_->insert(iter + current_position, subItem);
			current_position++;
			i++;
		}
	}
	// TODO: is it ok to manage object and it's pointer that came from outside inside this method?	
	delete items;
	items = nullptr;
}

void sentence::replace_all_sentence_words_start_with_consonant(int length)
{
}

std::string* sentence::get_sentence()
{
	auto* result = new std::string();
	for (auto& sentence : *sentence_items_)
	{
		if (sentence != nullptr)
		{
			result->append(*sentence->get_value());
		}		
	}
	return result;
}

sentence::~sentence()
{
	for (auto& item : *sentence_items_)
	{
		delete item;
		item = nullptr;
	}
	delete this->sentence_items_;
	sentence_items_ = nullptr;
}
