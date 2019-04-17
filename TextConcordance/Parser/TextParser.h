#pragma once
#include "Page.h";
#include "Word.h";
#include "Document.h";
#include "Concordance.h";
#include <string>;
using std::string;

//Processes document model and
	//provides list of words
class TextParser
{
public:
	TextParser(Document document);
	~TextParser();

	//Creating concordance of the document
	Concordance CreateConcordance();
private:
	vector<Page> pages;
	vector<Word> words;
	
	//Filling words list
	void FillInWordsList();

	//Join all lines on page with 'space' symbol
	//in one string. Ignores case of letters
	string JoinLines(Page page);

	//Check if list of words already contains word. If true
	//increases word.RepeatCount. Also check if word already
	//contain current page number
	bool IsWordsContainsWord(Word word);	
};

