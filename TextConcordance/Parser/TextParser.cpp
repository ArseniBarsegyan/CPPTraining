#include "stdafx.h"
#include "TextParser.h"
#include <algorithm>
#include <regex>
#include <string>
#include <iostream>

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
	std::regex reg("\\w+");
	this->words = vector<Word>();

	for (int i = 0; i < this->pages.size(); i++) {
		//Creating collection of all words on pages
		string pageText = JoinLines(pages.at(i));

		std::smatch match;

		std::regex_iterator<string::iterator> it(pageText.begin(), pageText.end(), reg);
		std::regex_iterator<string::iterator> end;

		for (; it != end; ++it)
		{
			vector<int> pageNumbers;
			Word word = Word(it->str(), 1, this->pages[i].GetCurrentPageNumber(), vector<int>());
			if (!IsWordsContainsWord(word)) {
				this->words.push_back(word);
			}
		}
	}
}

bool TextParser::IsWordsContainsWord(Word word)
{
	// & point to element without copying it into memory
	for (auto &w : words) {
		if (w.GetValue().compare(word.GetValue()) == 0) {
			w.IncreaseRepeatCount();

			vector<int> wordPageNumbers = w.GetPageNumbers();
			//Check if 'words[i]' already contains page number

			for (int &wordPageNumber : wordPageNumbers) {
				auto iter = std::find(wordPageNumbers.begin(), wordPageNumbers.end(), wordPageNumber);

				if (iter == wordPageNumbers.end()) {
					wordPageNumbers.push_back(wordPageNumber);
				}
			}
			return true;
		}		
	}
	return false;
}

string TextParser::JoinLines(Page page)
{
	string result;
	vector<string> lines = page.GetLines();
	for (string &line : lines) {
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		result.append(line);
		// Join lines and add a space between them
		result.append(" ");
	}
	return result;
}
