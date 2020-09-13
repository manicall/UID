#pragma once
#include <map>
#include <string>
#include <vector>

class Sports {

protected:
	std::vector<std::string> categories;
	std::vector<std::string> names;
	std::vector<std::string> descriptions;
	std::multimap<std::string, std::string> category_names;

public:
	std::vector<std::string> GetCategories() { return categories; }
	std::vector<std::string> GetNames() { return names; }
	std::vector<std::string> GetDescriptions() { return descriptions; }
	std::multimap<std::string, std::string> get_category_names() { return category_names; }
};

