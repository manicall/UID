#pragma once
#include "Summer.h"
#include "Winter.h"

class Categories {

	Summer summer;
	Winter winter;
	std::vector<std::string> names;


public:


	std::vector<std::string> GetNames() { return names; }
	Summer GetSummer() { return summer; }
	Winter GetWinter() { return winter; }

};