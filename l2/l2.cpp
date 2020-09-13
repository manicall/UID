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

void HideCursor() {
	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = false;
	CCI.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}


int main() {
	setlocale(LC_ALL, "ru");
	HideCursor();

	Menu menu;

	menu.DisplayMenu();	
	while (true)
	{
		menu.Control();
	}





	system("pause");
}