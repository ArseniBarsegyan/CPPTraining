#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Page.h"
#include "Document.h"
#include <sys/stat.h>
using std::vector;
using std::string;

//Creating a document model from text file
class DocumentCreator
{
public:
	DocumentCreator(string fileName, int numberOfLinesPerPage);
	~DocumentCreator();

	Document CreateDocumentModel();
private:
	vector<Page> pages;
	Page page;
	string fileName;
	int numberOfLinesPerPage;

	// Check if file exists
	inline bool IsFileExists(const std::string& name);
	void ReadFileContent();
};

