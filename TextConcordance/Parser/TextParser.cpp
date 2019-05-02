#include "stdafx.h"
#include "TextParser.h"
#include <algorithm>
#include <regex>
#include <string>

TextParser::TextParser(Document document)
{
	this->pages_ = document.get_pages();
}

TextParser::~TextParser()
{
}

Concordance TextParser::create_concordance()
{
	fill_in_words_list();
	return Concordance(this->words_);
}

void TextParser::fill_in_words_list()
{
	std::regex reg("\\w+");
	this->words_ = vector<Word>();

	for (int i = 0; i < this->pages_.size(); i++) {
		//Creating collection of all words on pages
		string page_text = join_lines(pages_.at(i));

		std::smatch match;

		std::regex_iterator<string::iterator> it(page_text.begin(), page_text.end(), reg);
		std::regex_iterator<string::iterator> end;
		
		for (; it != end; ++it)
		{
			auto page_numbers = new vector<int>();
			Word word = Word(it->str(), 1, this->pages_[i].get_current_page_number(), page_numbers);
			if (!is_words_contains_word(word)) {
				this->words_.push_back(word);
			}
		}
	}
}

bool TextParser::is_words_contains_word(Word word)
{
	// & point to element without copying it into memory
	for (auto &w : words_) {
		if (w.get_value() == word.get_value()) {
			w.increase_repeat_count();
			
			//Check if 'words[i]' already contains page number
			for (auto &number : *word.get_page_numbers())
			{
				if (!contains(*w.get_page_numbers(), number))
				{
					w.get_page_numbers()->push_back(number);
				}
			}
			return true;
		}		
	}
	return false;
}

// simple linear search
bool TextParser::contains(vector<int> numbers, int number)
{
	bool result;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers.at(i) == number)
		{
			return true;
		}
	}
	return false;
}

string TextParser::join_lines(Page page)
{
	string result;
	vector<string> lines = page.get_lines();
	for (string &line : lines) {
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		result.append(line);
		// Join lines and add a space between them
		result.append(" ");
	}
	return result;
}
