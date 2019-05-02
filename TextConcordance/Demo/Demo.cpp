#include "pch.h"
#include <iostream>
#include "Concordance.h"
#include "DocumentCreator.h"
#include "TextParser.h"
#include <chrono>

// Task: create text concordance of the text file.
// Concordance is a document where you can find list
// of words (ordered alphabetically) 
// that occurs in a document, their occurence count and
// number of pages where these words occur.
int main()
{
	// Measure app running time
	auto started = std::chrono::high_resolution_clock::now();

	// Read document from drive (we count that document 1.txt exists on drive D and 
	// every page contains 5 lines of text)
	DocumentCreator creator = DocumentCreator("D:\\1.txt", 5);
	try
	{
		Document document = creator.create_document_model();
		Concordance concordance = TextParser(document).create_concordance();
		concordance.WriteFile("D:\\3.txt");
		std::cout << "Concordance have been created successfully" << std::endl;
	}
	catch (char *c)
	{
		std::cout << "Document doesn't exists. Please check your app settings" << std::endl;
	}

	// Measure app running time
	auto done = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
	return 0;
}