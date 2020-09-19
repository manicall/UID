#include <iostream>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <ctime>
#include "Menu.h"

enum { ENTER = 13, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    ChangeColor("default");
    std::cout << "вывод меню на клавишу F2";
    std::wstring menu;
    createmenu(menu);
    std::string textUnderMenu[3];
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int step = 1;
    char c;
    SwitchEchoMode(false); // запрет на эхо мод в начале программы
    while (true) {
        c = _getch();
        switch (c) {
        case 60: {
            if (!IsMenuDisplayed) DisplayMenu(0, 0, menu);
            x1 = 0, y1 = 0;
            gotoxy(x1, y1);
            break;
        }
        case 0: break;
        case LEFT: if (IsMenuDisplayed) { gotoxy(x1 -= step, y1); } break;
        case RIGHT: if (IsMenuDisplayed) { gotoxy(x1 += step, y1); } break;
        case UP: if (IsMenuDisplayed) { gotoxy(x1, y1 -= step); } break;
        case DOWN: if (IsMenuDisplayed) { gotoxy(x1, y1 += step); } break;
        case ENTER: if (IsMenuDisplayed) {
            ChoiseMenu(x1, y1, textUnderMenu);
            HideMenu(textUnderMenu, x2, y2);
            break;
        }
        }
        if (c == 0 || c == 60) continue;
        if(!IsMenuDisplayed && echoMode) {
            if ((c == LEFT || c == RIGHT || c == UP || c == DOWN)) {
                gotoxy(--x2, y2);
                std::cout << " ";
                gotoxy(x2, y2);
                continue;
            }
            else std::cout << c;
            GetConsoleCursorPosition(x2, y2);
            if (x2 >= 0 && x2 <= 35 && y2 >= 0 && y2 <= 2) {
                textUnderMenu[y2] += c;
            }
        }
        if (IsMenuDisplayed) {
            if (c == 100 || c == -30)  {
                MessageBeep(0);
                return 0;
            }
            if (c == 97 || c == -12)  {
                ChangeColor("background");
                HideMenu(textUnderMenu, x2, y2);
                SwitchEchoMode(false);
            }
            if (c == 39 || c == -3) {
                MessageBeep(0);
                HideMenu(textUnderMenu, x2, y2);
                SwitchEchoMode(true);
            }
            if (c == 119 || c == -10)
            {
                ChangeColor("font");
                HideMenu(textUnderMenu, x2, y2);
                SwitchEchoMode(false);
            }
        }
        CheckBorders(x1, y1);
    }
    system("pause");
    return 0;
}