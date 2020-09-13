#pragma once
#include <string>
#include <vector>
#include <map>

class Winter {

	std::map<std::string, std::string> descriptions;
	std::vector<std::string> names;



public:

	Winter() {

		names = {  };
		descriptions = { std::make_pair("true", "1") };

	}

	std::map<std::string, std::string> GetDescription() { return descriptions; }
	std::vector<std::string> GetNames() { return names; }

};