#include <iostream>
#include "Menu.h"

/*������� ��� �������*/
void check_colors() {

	for (size_t i = 0; i < 16; i++)
		for (size_t j = 0; j < 16; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((i << 4) | j));
			std::cout << "���: " << i << " �����: " << j << " ������ ��� �������� �����" << std::endl;
		}

}
/*������� ��� �������*/


int main() {
	setlocale(LC_ALL, "ru");


	Menu menu;


	

	check_colors();
	//menu.DisplayFirstLevelMenu();

	/*����������� ��� �������� �� �����*/
	/*for (auto i : sum.get_category_names())
		if (i.first == sum.GetCategories()[0])
			std::cout << i.second << std::endl;*/


	system("pause");
}