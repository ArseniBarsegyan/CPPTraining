#include "pch.h"
#include <iostream>
#include "Concordance.h"
#include "DocumentCreator.h"
#include "TextParser.h"

int main()
{
	DocumentCreator creator = DocumentCreator("D:\\1.txt", 5);
	try
	{
		Document document = creator.CreateDocumentModel();
		Concordance concordance = TextParser(document).CreateConcordance();
		concordance.WriteFile("D:\\3.txt");
		std::cout << "Concordance have been created successfully";
	}
	catch (char *c)
	{
		std::cout << "Document doesn't exists. Please check your app settings";
	}
}