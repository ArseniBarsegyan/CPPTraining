#pragma once
#include <vector>
#include <string>
#include "Page.h"
#include "Document.h"

using std::vector;
using std::string;

// Create a document object model from text file
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
	// Read file content and create object models of pages from this file
	void read_file_content();
};

