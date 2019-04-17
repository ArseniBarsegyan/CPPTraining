#include "stdafx.h"
#include "TextParser.h"
#include <algorithm>
#include <regex>

TextParser::TextParser(Document document)
{
	this->pages = document.GetPages();
}

TextParser::~TextParser()
{
}

Concordance TextParser::CreateConcordance()
{
	FillInWordsList();
	return Concordance(this->words);
}

void TextParser::FillInWordsList()
{
	std::regex reg("[A-Za-z]+");
	this->words = vector<Word>();

	for (int i = 0; i < this->pages.size(); i++) {
		//Creating collection of all words on pages
		string pageText = JoinLines(pages.at(i));

		std::smatch match;
		if (std::regex_search(pageText, match, reg)) {
			for (int j = 0; j < match.size(); j++) {
				vector<int> pageNumbers;
				Word word = Word(match.str(j), 1, this->pages[i].GetCurrentPageNumber(), vector<int>());
				if (!IsWordsContainsWord(word)) {
					this->words.push_back(word);
				}
			}
		}
	}
}

bool TextParser::IsWordsContainsWord(Word word)
{
	for (int i = 0; i < this->words.size(); i++) {
		if (!this->words[i].GetValue().compare(word.GetValue)) {
			continue;
		}
		words[i].IncreaseRepeatCount();

		//Check if 'words[i]' already contains page number
		for (int j = 0; j < words[i].GetPageNumbers().size(); j++) {
			auto iter = std::find(words[i].GetPageNumbers().begin(), 
				words[i].GetPageNumbers().end(), words[i].GetPageNumbers()[j]);

			if (iter == words[i].GetPageNumbers().end()) {
				words[i].GetPageNumbers().push_back(words[i].GetPageNumbers()[j]);
			}
		}
		return true;
	}
	return false;
}

string TextParser::JoinLines(Page page)
{
	string result;
	auto lines = page.GetLines();
	for (auto i = 0; i < lines.size(); i++) {
		std::transform(lines.begin(), lines.end(), lines.begin(), ::tolower);
		result.append(lines.at(i));
	}
	return result;
}
