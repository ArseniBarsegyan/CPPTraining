#pragma once
#include "Page.h";
#include "Word.h";
#include "Document.h";
#include "Concordance.h";
#include <string>;
using std::string;

// Processes document model and
// provides list of words
class TextParser
{
public:
	TextParser(Document document);
	~TextParser();

	// Creating concordance of the document
	Concordance create_concordance();
private:
	vector<Page> pages_;
	vector<Word> words_;
	
	// Filling words list
	void fill_in_words_list();

	// Join all lines on page with 'space' symbol
	// in one string. Ignores case of letters
	string join_lines(Page page);

	// Check if list of words already contains word. If true
	// increases word.RepeatCount. Also check if word already
	// contain current page number
	bool is_words_contains_word(Word word);

	// Check if vector of numbers contains given number
	bool contains(vector<int> numbers, int number);
};

