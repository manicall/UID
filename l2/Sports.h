#pragma once
#include <string>
#include <map>
#include <vector>

class Sports {

protected:
	std::vector<std::string> sports;

public:

	Sports() { sports = { "������ �����", "������ �����" }; }
	void print() {
		for (std::string sport : sports)
		{
			std:: cout << sport;
		}
	};

	std::vector<std::string> GetSports() { return sports; }
};

class Summer : public Sports {

public:

	Summer() { sports = { " �����" }; }


};

class Winter : public Sports {

public:
	Winter() { sports = { " �����" }; }

};


