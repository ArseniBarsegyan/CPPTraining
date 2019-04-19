#include "pch.h"
#include <iostream>
#include "Concordance.h"
#include "DocumentCreator.h"
#include "TextParser.h"
#include <chrono>

int main()
{
	auto started = std::chrono::high_resolution_clock::now();

	DocumentCreator creator = DocumentCreator("D:\\1.txt", 5);
	try
	{
		Document document = creator.CreateDocumentModel();
		Concordance concordance = TextParser(document).CreateConcordance();
		concordance.WriteFile("D:\\3.txt");
		std::cout << "Concordance have been created successfully" << std::endl;
	}
	catch (char *c)
	{
		std::cout << "Document doesn't exists. Please check your app settings" << std::endl;
	}

	auto done = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
	return 0;
}