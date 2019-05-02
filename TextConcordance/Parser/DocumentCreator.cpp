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
	int count_lines = 1;
	int page_number = 1;
	this->page_ = Page(page_number, this->number_of_lines_per_page_, vector<string>());

	if (in.is_open()) {
		while (getline(in, line)) {
			// Start filling page.
			// When all lines of page are filled, add filled page to list of pages.
			// After that create new page and start filling it again. 
			// Counting of lines starts
			// from 1 again until new page will be filled.
			if (count_lines > this->number_of_lines_per_page_) {
				this->pages_.push_back(this->page_);
				page_number++;
				this->page_ = Page(page_number, this->number_of_lines_per_page_, vector<string>());
				count_lines = 1;
			}
			this->page_.add_line(line);
			count_lines++;
		}
	}
	this->pages_.push_back(this->page_);
	in.close();
}

