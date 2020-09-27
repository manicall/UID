#include "Menu.h"
#include <iostream>
//#define DEBUG
/*������� ��� �������*/
void check_colors() {

	for (size_t i = 0; i < 16; i++)
		for (size_t j = 0; j < 16; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((i << 4) | j));
			std::cout << "���: " << i << " �����: " << j << " ������ ��� �������� �����" << std::endl;
		}

}
/*������ ������*/
void HideCursor() {
	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = false;
	CCI.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
}

int main() {
	setlocale(LC_ALL, "ru");
#ifdef DEBUG
	check_colors();
#endif // DEBUG
	HideCursor();
	Menu menu;
	menu.DisplayMenu(0);	
	while (true)
	{
		menu.Control();
	}
	system("pause");
}