#include "stdafx.h"
#include "DocumentCreator.h"
#include <fstream>
#include <sys/stat.h>

using std::vector;
using std::string;
using std::ifstream;

DocumentCreator::DocumentCreator(string file_name, int number_of_lines_per_page)
{
	this->file_name_ = file_name;
	this->number_of_lines_per_page_ = number_of_lines_per_page;
}

DocumentCreator::~DocumentCreator()
{
}

Document DocumentCreator::create_document_model()
{
	if (!this->is_file_exists(this->file_name_)) {
		throw STG_E_FILENOTFOUND;
	}
	read_file_content();
	return Document(this->file_name_, this->pages_);
}

// Check if file exists
inline bool DocumentCreator::is_file_exists(const std::string & name)
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

void DocumentCreator::read_file_content()
{
	ifstream in(this->file_name_);
	this->pages_ = vector<Page>();

	string line;
	int countLines = 1;
	int pageNumber = 1;
	this->page_ = Page(pageNumber, this->number_of_lines_per_page_, vector<string>());

	if (in.is_open()) {
		while (getline(in, line)) {
			// When all lines of page are filled adding filled page to list of pages
			// Creating new page and start filling it again. Counting of lines starting again
			if (countLines > this->number_of_lines_per_page_) {
				this->pages_.push_back(this->page_);
				pageNumber++;
				this->page_ = Page(pageNumber, this->number_of_lines_per_page_, vector<string>());
				countLines = 1;
			}
			this->page_.add_line(line);
			countLines++;
		}
	}
	this->pages_.push_back(this->page_);
	in.close();
}

