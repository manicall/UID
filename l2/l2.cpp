#include <iostream>
#include "Menu.h"

/*функция для отладки*/
void check_colors() {

	for (size_t i = 0; i < 16; i++)
		for (size_t j = 0; j < 16; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((i << 4) | j));
			std::cout << "фон: " << i << " шрифт: " << j << " фукция для проверки цвета" << std::endl;
		}

}
/*функция для отладки*/


int main() {
	setlocale(LC_ALL, "ru");


	Menu menu;


	

	check_colors();
	//menu.DisplayFirstLevelMenu();

	/*распечатать все значения по ключу*/
	/*for (auto i : sum.get_category_names())
		if (i.first == sum.GetCategories()[0])
			std::cout << i.second << std::endl;*/


	system("pause");
}