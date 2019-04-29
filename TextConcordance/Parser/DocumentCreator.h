#pragma once
#include <vector>
#include <string>
#include "Page.h"
#include "Document.h"

using std::vector;
using std::string;

//Creating a document model from text file
class DocumentCreator
{
public:
	DocumentCreator(string file_name, int number_of_lines_per_page);
	~DocumentCreator();

	Document create_document_model();
private:
	vector<Page> pages_;
	Page page_;
	string file_name_;
	int number_of_lines_per_page_;

	// Check if file exists
	inline bool is_file_exists(const std::string& name);
	void read_file_content();
};

