#include "pch.h"
#include "sentence.h"
#include <typeinfo>
#include <regex>

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

bool sentence::contains(std::string value, char symbol)
{
	bool contains = false;
	for (auto& letter : value)
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

std::vector<sentence_item*>* sentence::get_all_unique_words(int length)
{
	std::vector<sentence_item*>* words = new std::vector<sentence_item*>();

	for (auto i = 0; i < sentence_items_->size(); ++i)
	{
		auto& item = *sentence_items_->at(i);
		const std::type_info& type_info = typeid(item);
		if (type_info != typeid(word))
		{
			continue;
		}
		if (item.get_value().size() != length)
		{
			continue;
		}
		// TODO: push item
		words->push_back(*item);
	}
	auto groups = create_groups(sentence_items_);
	// TODO: loop at groups keys
	return groups;
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
		if (item.get_value().size() != word_length)
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
}

void sentence::remove_all_sentence_words_start_with_consonant_by_length(int length)
{
	for (auto& item : *sentence_items_)
	{
		if (item != nullptr)
		{
			auto item_value = item->get_value();

			if (item_value.size() == length)
			{
				std::regex reg(R"(\b[b-d,f-h,j-n,p-t,v,w,x,z]\S+\b)");
				std::smatch match;

				if (std::regex_match(item_value.begin(), item_value.end(), reg))
				{
					delete item;
					item = nullptr;
				}
			}
		}		
	}
}

std::string sentence::get_sentence()
{
	auto result = std::string();
	for (auto& sentence : *sentence_items_)
	{
		if (sentence != nullptr)
		{
			result.append(sentence->get_value());
		}		
	}
	return result;
}

std::map<std::string, std::vector<sentence_item*>*>* sentence::create_groups(std::vector<sentence_item*>* sentence_items)
{
	auto groups = new std::map<std::string, std::vector<sentence_item*>*>();

	for (sentence_item* wrd : *sentence_items) {
		std::string word_group_key = wrd->get_value();
		auto group = *groups->find(word_group_key);

		if (group != *groups->end()) {
			// put word in group's words.
			groups->at(word_group_key)->push_back(wrd);
		}
		else {
			// create new group, add words collection and insert word to this collection.
			groups->insert(std::make_pair(word_group_key, new std::vector<sentence_item*>()));
			groups->at(word_group_key)->push_back(wrd);
		}
	}
	return groups;
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
