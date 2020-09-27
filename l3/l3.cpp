// l3.cpp : Определяет точку входа для приложения.
//

#include "графика.h"
#include "framework.h"
#include "l3.h"
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

std::wstring text;
OPENFILENAME ofn;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK   PviewDlgProc1(HWND    hWnd, UINT    wMsg, WPARAM  wParam, LPARAM  lParam);
BOOL CALLBACK   PviewDlgProc2(HWND    hWnd, UINT    wMsg, WPARAM  wParam, LPARAM  lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    ULONG_PTR token;
    GdiplusStartupInput input;
    input.GdiplusVersion = 1;
    GdiplusStartup(&token, &input, NULL);

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_L3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);   
    }
    GdiplusShutdown(token);
    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_L3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


inline void ShowDialog1(std::wstring& text, Sports& sport, int index) {
    text = sport.GetDescriptions()[index].data();
    DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, PviewDlgProc1);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    Summer summer;
    Winter winter;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case ID_32771: ShowDialog1(text, summer, 0); break;
            case ID_32793: ShowDialog1(text, summer, 1); break;
            case ID_32777: ShowDialog1(text, summer, 2); break;
            case ID_32778: ShowDialog1(text, summer, 3); break;
            case ID_32794: ShowDialog1(text, summer, 4); break;
            case ID_32780: ShowDialog1(text, summer, 5); break;
            case ID_32781: ShowDialog1(text, summer, 6); break;
            case ID_32782: ShowDialog1(text, summer, 7); break;
            case ID_32788: ShowDialog1(text, winter, 0); break;
            case ID_32789: ShowDialog1(text, winter, 1); break;
            case ID_32790: ShowDialog1(text, winter, 2); break;
            case ID_32791: ShowDialog1(text, winter, 3); break;
            case ID_32792: ShowDialog1(text, winter, 4); break;
            case ID_32785: ShowDialog1(text, winter, 5); break;
            case ID_32786: ShowDialog1(text, winter, 6); break;
            case ID_32795: ShowDialog1(text, winter, 7); break;

            case ID_HELP:
                MessageBox(0, L"Летние и зимние виды спорта", L"Помощь", 0);
                break;
            case ID_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

bool OpenFile(OPENFILENAME& ofn) {

    static wchar_t szFilter[] = L"JPEG Image (*.JPG)\0*.jpg\0"
       L"All Files (*.*)\0*.*\0\0";

    static wchar_t szFileName[_MAX_PATH];
    static wchar_t szTitleName[_MAX_FNAME + _MAX_EXT];
    //структура для сообщения о выделении строки в текстовом поле

    ofn.lStructSize = sizeof(OPENFILENAME);	//размер структуры
    ofn.hwndOwner = NULL;	//дискриптор окна владельца
    ofn.hInstance = NULL;	//хендел потока родителя
    ofn.lpstrFilter = szFilter;	//строка допустимых фильтров выбора файлов
    ofn.lpstrCustomFilter = NULL;	//строка с выбранным фильтром
    ofn.nMaxCustFilter = 0;	//длина строки предыдущего поля
    ofn.nFilterIndex = 0;	//индекс выбранной строки фильтра
    ofn.lpstrFile = NULL;	//строка с выбранным файлом и путем к нему
    ofn.nMaxFile = _MAX_PATH;	//максимально допустимая длина предыдущей строки
    ofn.lpstrFileTitle = NULL;	//строка с именем выбранного файла
    ofn.nMaxFileTitle = _MAX_FNAME + _MAX_EXT;  //макс.допустимая  длина пред. строки
    ofn.lpstrInitialDir = NULL;	//имя каталога
    ofn.lpstrTitle = NULL;	//строка с заголовком диалогового окна
    ofn.Flags = 0;	//Флаги диалогового окна
    ofn.nFileOffset = 0;	//Смещение имени файла в строке
    ofn.nFileExtension = 0;	//Смещение расширения файла в строке
    ofn.lpstrDefExt = L"jpg";	//расширение выбираемых файлов по-умолчанию
    ofn.lCustData = 0L;	//данные для обработки
    ofn.lpfnHook = NULL;	//указатель для функции обработки (ФОВ)
    ofn.lpTemplateName = NULL;	//имя шаблона диалогового окна

   //указываем положение буферов для получения результатов
    ofn.lpstrFile = szFileName;
    ofn.lpstrFileTitle = szTitleName;
    //отображать все файлы
    ofn.Flags = OFN_HIDEREADONLY | OFN_CREATEPROMPT;

    return GetOpenFileName(&ofn);
}
//Процедура обработки сообщений диалогового окна
BOOL CALLBACK   PviewDlgProc1(HWND    hDlg,
    UINT    wMsg,
    WPARAM  wParam,
    LPARAM  lParam)
{
    switch (wMsg)
    {
        // сообщение об инициализации диалоговой формы
    case WM_INITDIALOG:


        SetWindowText(GetDlgItem(hDlg, IDC_STATIC), text.data());

        break;
    case WM_CLOSE:
        EndDialog(hDlg, (INT_PTR)TRUE);
        break;
    case WM_PAINT:
    {
        static PAINTSTRUCT ps; // структура для перерисовки окна
        HDC hdc = BeginPaint(hDlg, &ps); // получить контекст устройства

        EndPaint(hDlg, &ps);
        break;
    }
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            EndDialog(hDlg, (INT_PTR)TRUE);
            break;
        case IDC_BUTTON1:
        {
            if (OpenFile(ofn)) {
                EndDialog(hDlg, (INT_PTR)TRUE);
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), 0, PviewDlgProc2);
            }
            break;
        }
        default:
            return FALSE;
        }
        break;

    default:
        return FALSE;
    }

    return TRUE;
}
BOOL CALLBACK   PviewDlgProc2(HWND    hDlg,
    UINT    wMsg,
    WPARAM  wParam,
    LPARAM  lParam)
{
    static int lx = 146, ly = 163;
    static RECT rect; // координаты прямоугольника
    static HDC hdc, hdcm; // контекст устройтва
    static PAINTSTRUCT ps; // структура для перерисовки окна
    static HBITMAP hbm; // дескриптор изображения
    static HBRUSH hbr; // дескриптор кисти
    switch (wMsg)
    {
        // сообщение об инициализации диалоговой формы
    case WM_INITDIALOG:
        SetWindowText(GetDlgItem(hDlg, IDC_STATIC2), text.data());
        break;
    case WM_CLOSE:
        EndDialog(hDlg, (INT_PTR)TRUE);
        break;
    case WM_PAINT:
    {
        static PAINTSTRUCT ps; // структура для перерисовки окна
        HDC hdc = BeginPaint(GetDlgItem(hDlg, IDC_STATIC1), &ps); // получить контекст устройства
        DrawImage(hdc, ofn.lpstrFile,7, 7, lx+50, ly+50);
        EndPaint(GetDlgItem(hDlg, IDC_STATIC1), &ps);
        break;
    }
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            EndDialog(hDlg, (INT_PTR)TRUE);

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