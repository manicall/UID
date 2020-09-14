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
    std::wstring menu;
    createmenu(menu);
    std::string textUnderMenu[3];
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int step = 1;
    char c;
    while (true) {
        c = _getch();
        if (c < 0) continue;
        switch (c) {
        case 60: {
            if (!IsMenuDisplayed) DisplayMenu(0, 0, menu);
            x1 = 0;
            y1 = 0;
            gotoxy(x1, y1);
            break;
        }
        case 0: break;
        case LEFT: if (IsMenuDisplayed) { gotoxy(x1 -= step, y1); } break;
        case RIGHT: if (IsMenuDisplayed) { gotoxy(x1 += step, y1); } break;
        case UP: if (IsMenuDisplayed) { gotoxy(x1, y1 -= step); } break;
        case DOWN: if (IsMenuDisplayed) { gotoxy(x1, y1 += step); } break;
        case 100: if (IsMenuDisplayed) { return 0; }
        case 97: if (IsMenuDisplayed) {
            HideMenu(textUnderMenu, x2, y2);
            SwitchEchoMode(false);
            ChangeColor("background");
            break;
        }
        case ENTER: if (IsMenuDisplayed) {
            HideMenu(textUnderMenu, x2, y2);
            ChoiseMenu(x1, y1, textUnderMenu);
            break;
        }
        case 39: if (IsMenuDisplayed) {
            HideMenu(textUnderMenu, x2, y2);
            SwitchEchoMode(true);
            break;
        }
        case 119: if (IsMenuDisplayed) {
            HideMenu(textUnderMenu, x2, y2);
            SwitchEchoMode(false);
            ChangeColor("font");
            break;
        }
        default:
            if (!IsMenuDisplayed && echoMode) {
                std::cout << c;
                GetConsoleCursorPosition(x2, y2);
                if (x2 >= 0 && x2 <= 35 && y2 >= 0 && y2 <= 2) {
                    textUnderMenu[y2] += c;
                }
                break;
            }
        }
        CheckBorders(x1, y1);

    }
    system("pause");
    return 0;
}