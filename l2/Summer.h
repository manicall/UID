#pragma once
#include <string>
#include <vector>
#include <map>

class Summer {

	std::map<std::string, std::string> descriptions;
	std::vector<std::string> names;


public:

	Summer() {
	
		names = {  };
		descriptions = {  };

	
	}

	std::map<std::string, std::string> GetDescription() { return descriptions; }
	std::vector<std::string> GetNames() { return names; }


};
