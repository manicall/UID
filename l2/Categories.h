#pragma once
#include "Summer.h"
#include "Winter.h"

class Categories {

	Summer Summer;
	Winter winter;
	std::vector<std::string> names;


public:


	std::vector<std::string> GetNames() { return names; }

};