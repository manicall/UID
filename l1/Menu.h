#pragma once
#include <string>
bool IsMenuDisplayed = false; // отображаетс€ ли меню
bool echoMode = true;
/*переместить курсор по координатам*/
void gotoxy(const int &x,const int& y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*получить координаты консоли*/
void GetConsoleCursorPosition(int& x, int& y)
{
    COORD c;
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi))
    {
        c = cbsi.dwCursorPosition;
        x = c.X;
        y = c.Y;
    }
    else
    {
        x = 0;
        y = 0;
        std::cout << "ERROR";
    }
}
/*горизонтальные линии меню*/
void HorisontLine(const char* str, std::wstring menu[], std::wstring& wstr) {
    int num;
    if (!strcmp(str, "upper")) num = 9516;
    else if (!strcmp(str, "lower")) num = 9524;
    else {
        std::wcout << "SOME TROUBLE";
        return;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < menu[i].length(); j++) {
            wstr += wchar_t(9472);
        }
        if (i == 3) break;
        wstr += wchar_t(num);
    }
}
/*создание меню*/
void createmenu(std::wstring& wstr) {
    std::wstring menu[]{
    L" ÷вет вывода ",
    L" ‘он ",
    L" Ёхо ",
    L" ¬ыход ",
    };
    wstr = wchar_t(9484);
    HorisontLine("upper", menu, wstr);
    wstr += wchar_t(9488);
    wstr += '\n';
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) wstr += wchar_t(9474) + menu[i] + wchar_t(9474);
        else wstr += menu[i];
    }
    wstr += wchar_t(9474);
    wstr += '\n';
    wstr += wchar_t(9492);
    HorisontLine("lower", menu, wstr);
    wstr += wchar_t(9496);
    wstr += '\n';
}
/*переключить отображение меню*/
void SwitchEchoMode(bool condition) {
    echoMode = condition;
}
void SwitchIsMenuDisplayed(bool condition) {
    IsMenuDisplayed = condition;
}

/*
изменить цвет шрифта или фона
font - изменить цвет шрифта
background - изменить цвет фона
default - цвет шрифта и фона по умолчанию
*/
void ChangeColor(const char* attrubute)
{
    std::string color = "color ";
    int static font = 0, background = 7;
    int _font = font; // последний цвет шрифта 
    int _background = background; // последний цвет фона
    do {
        if (!strcmp(attrubute, "font"))
            while (_font == font || font == background)
                font = rand() % 16;
        else if (!strcmp(attrubute, "background"))
            while (_background == background || font == background)
                background = rand() % 16;
    } while (font == background);
    if (!strcmp(attrubute, "default"))
    {
        font = 7, background = 0;
    }

    if (background > 9) color += char(background + 55);
    else color += std::to_string(background);
    if (font > 9) color += char(font + 55);
    else color += std::to_string(font);

    system(color.data());
    if (IsMenuDisplayed) Beep(1000, 300);
}
/*закрасить меню*/
void HideMenu(std::string textUnderMenu[]) {

    for (int i = 0; i < 3; i++) {
        gotoxy(0, i);
        std::cout << textUnderMenu[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = textUnderMenu[i].length(); j < 35; j++) {
            gotoxy(j, i);
            std::cout << (char)32;
        }
    }
    SwitchIsMenuDisplayed(false);
}
/*скрыть меню*/
void HideMenu(std::string textUnderMenu[], int x, int y) {

    for (int i = 0; i < 3; i++) {
        gotoxy(0, i);
        std::cout << textUnderMenu[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = textUnderMenu[i].length(); j < 35; j++) {
            gotoxy(j, i);
            std::cout << (char)32;
        }
    }
    gotoxy(x, y);
    SwitchIsMenuDisplayed(false);
}
/*выбор пункта меню*/

void ChoiseMenu(int x, int y, std::string textUnderMenu[]) {
    if (y) {
        if (x >= 1 && x <= 13) {
            ChangeColor("font");
            SwitchEchoMode(false);
        }
        else if (x >= 15 && x <= 19) {
            ChangeColor("background");
            SwitchEchoMode(false);

        }
        else if (x >= 21 && x <= 25)
        {
            SwitchEchoMode(true);
            Beep(1000, 300);
        }
        else if (x >= 27 && x <= 33) {
            Beep(1000, 300);
            exit(0);
        }
    }
}
/*недает курсору выйти за границы*/

void CheckBorders(int& x, int& y) {
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= 120) x = 120;
}
/*отобразить меню*/
void DisplayMenu(int x, int y, std::wstring& wstr) {
    _setmode(_fileno(stdout), _O_U8TEXT);
    gotoxy(x, y);
    std::wcout << wstr.data();
    _setmode(_fileno(stdout), _O_TEXT);
    SwitchIsMenuDisplayed(true);
}
