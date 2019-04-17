#include "stdafx.h"
#include "DocumentCreator.h"
using std::vector;
using std::string;
using std::ifstream;

DocumentCreator::DocumentCreator(string fileName, int numberOfLinesPerPage)
{
	this->fileName = fileName;
	this->numberOfLinesPerPage = numberOfLinesPerPage;
}

DocumentCreator::~DocumentCreator()
{
}

Document DocumentCreator::CreateDocumentModel()
{
	if (!this->IsFileExists(this->fileName)) {
		throw STG_E_FILENOTFOUND;
	}
	ReadFileContent();
	return Document(this->fileName, this->pages);
}

// Check if file exists
inline bool DocumentCreator::IsFileExists(const std::string & name)
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

void DocumentCreator::ReadFileContent()
{
	ifstream in(this->fileName);
	this->pages = vector<Page>();

	string line;
	int countLines = 1;
	int pageNumber = 1;
	this->page = Page(pageNumber, this->numberOfLinesPerPage, vector<string>());

	if (in.is_open()) {
		while (getline(in, line)) {
			if (countLines > this->numberOfLinesPerPage) {
				this->pages.push_back(this->page);
				pageNumber++;
				this->page = Page(pageNumber, this->numberOfLinesPerPage, vector<string>());
				countLines++;
			}
			this->page.AddLine(line);
			countLines++;
		}
	}
	this->pages.push_back(this->page);
	in.close();
}

