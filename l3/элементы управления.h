#pragma once
#undef UNICODE
#include <string>
#include <windows.h>
HWND CreateEdit(HWND parent, int x, int y, int width, int height, HINSTANCE hInst, std::string name = "") {
    HWND h = CreateWindow("edit", name.data(),
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, x, y, width,
        height, parent, 0, hInst, NULL);
    ShowWindow(h, SW_SHOWNORMAL);
    return h;
}
HWND CreateButton(HWND parent, int x, int y, int width, int height, HINSTANCE hInst, std::string name = "кнопка") {
    HWND h = CreateWindow("button", name.data(),
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        x, y, width, height, parent, 0, hInst, NULL);
    ShowWindow(h, SW_SHOWNORMAL);
    return h;
}
HWND CreateStatic(HWND parent, int x, int y, int width, int height, HINSTANCE hInst, std::string name = "") {
    HWND h = CreateWindow("static", name.data(), WS_CHILD | WS_VISIBLE,
        x, y, width, height, parent, 0, hInst, NULL);
    ShowWindow(h, SW_SHOWNORMAL);
    return h;
}