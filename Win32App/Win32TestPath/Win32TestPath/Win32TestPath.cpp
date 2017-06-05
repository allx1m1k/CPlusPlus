// Win32TestPath.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32TestPath.h"
#include <objidl.h>
#include <gdiplus.h>
#include <Winuser.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")


#define MAX_LOADSTRING 100
#define TIMER_SECOND 1		// first timer identified by integer 1

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    StartTimer(HWND, UINT, WPARAM, LPARAM); //callback for start timer dialog
VOID CALLBACK MyTimerProc(HWND, UINT, UINT_PTR, DWORD);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);



    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
	
    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32TESTPATH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32TESTPATH));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32TESTPATH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32TESTPATH);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   
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

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE: 
		{
			
			//SetTimer(hWnd, TIMER_SECOND, 1000, (TIMERPROC)MyTimerProc);
		}
		break;

	case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case IDM_STARTTIMER:
				// Upon menu selection, we want to initialize the timer:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, StartTimer);
				SetTimer(hWnd, TIMER_SECOND, 1000, (TIMERPROC)MyTimerProc);
				break;
			
			case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
				KillTimer(hWnd, TIMER_SECOND);
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
            // TODO: Add any drawing code that uses hdc here...
			
				// ::Rectangle(hdc, 10, 12, 600, 350 );
			Graphics graphics(hdc);
			Pen      pen(Color(255, 0, 0, 255));
			graphics.DrawLine(&pen, 0, 0, 200, 100);


			Image image(L"C:\\Users\\DPeltik\\Pictures\\p1.jpg");
			graphics.DrawImage(&image, 60, 10);

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

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
	
    return (INT_PTR)FALSE;
}

// Message handler for start timer box.
INT_PTR CALLBACK StartTimer(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}

	return (INT_PTR)FALSE;
}



VOID CALLBACK MyTimerProc(HWND hWnd, UINT message, UINT_PTR idTimer, DWORD dwTime)
{
	//MessageBeep(1);
	static BOOL fFlipFlop = FALSE;
	HBRUSH      hBrush;
	HDC         hdc;
	RECT        rc;

	//MessageBeep(-1);
	fFlipFlop = !fFlipFlop;

	GetClientRect(hWnd, &rc);

	hdc = GetDC(hWnd);
	hBrush = CreateSolidBrush(fFlipFlop ? RGB(255, 0, 0) : RGB(0, 0, 255));

	FillRect(hdc, &rc, hBrush);
	ReleaseDC(hWnd, hdc);
	DeleteObject(hBrush);

}
