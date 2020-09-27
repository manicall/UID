#pragma once
#include <map>
#include <string>
#include <vector>


class Sports {

protected:
	std::vector<std::string> categories;
	std::vector<std::string> names;
	std::vector<std::wstring> descriptions;
	std::multimap<std::string, std::string> category_names;

public:
	std::vector<std::string> GetCategories() { return categories; }
	std::vector<std::string> GetNames() { return names; }
	std::vector<std::wstring> GetDescriptions() { return descriptions; }
	std::multimap<std::string, std::string> get_category_names() { return category_names; }
	/*найти все значения по ключу*/
	std::vector<std::string> FindAllValues(std::string key) {
		std::vector<std::string> values;
		for (auto i : category_names) {
			if (i.first == key)
				values.push_back(i.second);
		}
		return values;
	}
};

