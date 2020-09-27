#pragma once
#include <windows.h>
#include <string>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

void DrawImage(HDC hdc, std::wstring path, int x = 0, int y = 0, int width = 0, int height = 0)
{
    Graphics graphics(hdc);
    Image image(path.data());
    Rect destRect(x, y, width, height);
    graphics.DrawImage(&image, destRect);
}