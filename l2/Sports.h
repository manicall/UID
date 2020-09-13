#pragma once
#include "Categories.h"

class Sports {

	Categories categories;
	std::vector<std::string> names;

public:
	
	Sports() { names = { "������ �����", "������ �����" }; }
	
	void print() {
		for (std::string name : names)		
			std:: cout << name;	
	};

	std::vector<std::string> GetNames() { return names; }
	Categories GetCategories() { return categories; }
};
