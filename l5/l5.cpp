#undef UNICODE
#include <windows.h>
#include <string>
#include "resource.h"

static int lx = 150, ly = 200; // координаты конца экрана	
HWND hWndDialog, hWndPanel;
HINSTANCE       ghInstance;   // Переменная для хранения хендела процесса                      
// Описание используемой оконной процедуры
BOOL CALLBACK   PviewDlgProc(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam);
// Главное приложение программы
int WINAPI    WinMain(HINSTANCE   hInstance,
	HINSTANCE   hPrevInstance,
	LPSTR       lpCmdLine,
	int         nCmdShow)
{
	MSG msg;
	ghInstance = hInstance;
	// Создание  диалогового окна
	hWndDialog = CreateDialogParam(hInstance,
		MAKEINTRESOURCE(IDD_DIALOG1),
		NULL,
		(DLGPROC)PviewDlgProc,
		(LONG)0);
	ShowWindow(hWndDialog, nCmdShow);
	UpdateWindow(hWndDialog);
	hWndPanel = CreateWindowEx(WS_EX_CLIENTEDGE | WS_EX_DLGMODALFRAME, "STATIC", "",
		WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | SS_SUNKEN, 0, 0, lx + 10, ly + 10, hWndDialog, (HMENU)NULL, GetModuleHandle(0), (LPVOID)NULL);
	ShowWindow(hWndPanel, nCmdShow);
	UpdateWindow(hWndPanel);
	// Стандартный цикл обработки сообщений приложения
	while (GetMessage(&msg, NULL, 0, 0))
		if (!IsDialogMessage(hWndDialog, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	DestroyWindow(hWndDialog);
	return 0;
}

//Процедура обработки сообщений диалогового окна
BOOL CALLBACK   PviewDlgProc(HWND    hWnd,
	UINT    wMsg,
	WPARAM  wParam,
	LPARAM  lParam)
{
	static int x, y;
	static RECT rect; // координаты прямоугольника
	static HDC hdc, hdcm; // контекст устройтва
	static PAINTSTRUCT ps; // структура для перерисовки окна
	static HBITMAP hbm; // дескриптор изображения
	static HBRUSH hbr; // дескриптор кисти
	int first, second;
	std::string str;
	
	switch (wMsg)
	{
		// сообщение об инициализации диалоговой формы
	case WM_INITDIALOG:
		hdc = GetDC(hWndPanel); // получаем контекст устройства окна hWnd
		// создать в памяти контекст устройства hdcm,
		// совместимый с текущим контекстом устройства вывода hdc.
		hdcm = CreateCompatibleDC(hdc);
		x = 0, y = 0;
		// Создать изображение в памяти заданного размера
		hbm = CreateCompatibleBitmap(hdc, lx, ly);
		// установить в контексте hdcm устройства изображение hbm
		SelectObject(hdcm, hbm);
		// установить цвет кисти белый
		hbr = (HBRUSH)GetStockObject(WHITE_BRUSH);
		// установить в контексте устройства hdcm кисть hbr
		SelectObject(hdcm, hbr);

		// закрашивает прямоугольную область с координатами(x, y), шириной width
		// и высотой height, используя текущую кисть и растровую операцию dwRaster
		// PATCOPY - область заполняется текущей кистью;
		PatBlt(hdcm, 0, 0, lx, ly, PATCOPY);
		// объявляет недействительным прямоугольник *lpRect в окне hWnd
		InvalidateRect(hWndPanel,
			NULL, // перерисовать все окно
			false); // если true перерисовать фон окна


		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWndPanel, &ps); // получить контекст устройства
		BitBlt(hdc,        // контекст устройства приемника изображения;
			0, 0,         // x, y-координата левого верхнего угла приемни-ка;
			lx, ly,      // ширина и высота изображения;
			hdcm,       // контекст устройства источника изображения;
			0, 0,	   // x, y-координата левого верхнего угла источника;
			SRCCOPY);
		EndPaint(hWndPanel, &ps);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
			SendMessage(GetDlgItem(hWndDialog, IDC_EDIT1), WM_GETTEXT, 20, (LPARAM)str.data());
			first = atoi(str.data());
			SendMessage(GetDlgItem(hWndDialog, IDC_EDIT2), WM_GETTEXT, 20, (LPARAM)str.data());
			second = atoi(str.data());
			TextOut(hdcm, x, y, std::to_string(first+second).data(), std::to_string(first + second).size()); // вывести текст на экран
			y += 18;
			InvalidateRect(hWndPanel, NULL, false);
			break;

		default:
			return FALSE;
		}
		break;

	default:
		return FALSE;
	}

	return TRUE;
}

