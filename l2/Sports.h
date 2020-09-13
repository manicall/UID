#pragma once
#include <string>
#include <vector>

class Sports {

protected:
	std::vector<std::string> categories;
	std::vector<std::string> names;
	std::vector<std::string> descriptions;

public:
	


	std::vector<std::string> GetCategories() { return categories; }
	std::vector<std::string> GetNames() { return names; }
	std::vector<std::string> GetDescriptions() { return descriptions; }

};

