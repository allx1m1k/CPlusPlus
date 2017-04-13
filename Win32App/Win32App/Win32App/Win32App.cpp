//Sync with note
// ������� ���� ��� ������ �������
// Visual Studio C++ WinApi

// ���������� ���������� Windows ��� Win32
#include <windows.h>

// ��������� �������� CALLBACK �������
LRESULT CALLBACK MainWindowClassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// ������� WinAPI ��� ����� ����� � ���������
int WINAPI WinMain(
	HINSTANCE hInstance,		//handle � �������� ���������� ����������
	HINSTANCE hPrevInstance,	//handle � ����������� ���������� ����������
	LPSTR lpCmdLine,			//����� ��������� ������
	int nShowCmd)				//��� ����
{
	// ����������� ������ ����
	// ��������� ���������� ���� WNDCLASSEX

	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(WNDCLASSEX)); // �������� ������

	// ��������� ��������� WNDCLASSEX
	wClass.style = CS_HREDRAW | CS_VREDRAW; //����� ����
	wClass.lpfnWndProc = (WNDPROC)MainWindowClassProc; // ��������� ��������� ����
	wClass.hInstance = hInstance; // hInstance window
	wClass.cbSize = sizeof(WNDCLASSEX); // ������ ����� ������� ���������
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW; // ���������� ��� ����
	wClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wClass.lpszClassName = L"MainWindowClass"; // ��� ������


	// ���� ��������� ������, �� ������� ���������
	if (!RegisterClassEx(&wClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"����� ���� �� ��� ������!", L"������", MB_ICONERROR);
	}

	// ������� ���� ��� ������ ������� WinApi CreateWindowEx, �������� handle � ����
	HWND hWindow = CreateWindowEx(NULL,
		//L"MainWindowClass", 
		wClass.lpszClassName, // ��� ������, ������� �� ���������� ����� ��� ����������� ����
		L"��� ������ ���� � WinApi", // ��������� ����
		WS_OVERLAPPEDWINDOW,
		300, // x ���������� �� �����������
		200, // y ���������� �� ���������
		640, // ������ ������������ ����
		480, // ������ ������������ ����
		NULL,
		NULL,
		hInstance, // ���������� ���������� ����������
		NULL);

	// ���� ���� �� ���� �������, �� ������ ���������
	if (!hWindow)
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"���� �� ���� �������!", L"������", MB_ICONERROR);
	}

	//��� ��� ����� ������ ����

	// ��������� ���������� ��� ��������� ���� MSG
	MSG msg;
	// �������� ������ �� ������� ��������� MSG
	ZeroMemory(&msg, sizeof(MSG));

	// ������� ���� ���
	HMENU hMenuBar = CreateMenu();
	//HMENU hMenuBar = GetMenu(hWindow);
	
	// ���� ���� �� ���� �������, �� ������ ���������
	if (!hMenuBar)
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"���� �� ���� �������!", L"������ �������� ����", MB_ICONERROR);
	}

	// ��������� ����� ����
	AppendMenu(
		hMenuBar,
		MFT_STRING | MF_POPUP,
		100, //��������� ��� �����
		L"MenuBar100");

	// ��������� ����� ����
	AppendMenu(
		hMenuBar,
		MFT_STRING | MF_POPUP,
		101, //��������� ��� �����
		L"MenuBar101");

	/*
	InsertMenuItem(
		hMenuBar,	// handle ����
		1,			// ��������� ������� ����
		TRUE,		// ���������������� ����� ���� ��� ������� � �� ������������
		NULL);		// ������ MENUITEMINFO
	*/

	// ���������� ���� � ������ ������ � ����
	SetMenu(hWindow, hMenuBar);
	DrawMenuBar(hWindow);	
	ShowWindow(hWindow, nShowCmd);
	
	
					
	// ���� ��������� ���������
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

// ���������� ��������� ��������� ������ (WinApi)

LRESULT CALLBACK MainWindowClassProc(
	HWND hwnd,     // handle ����
	UINT uMsg,     // ������������� ���������
	WPARAM wParam, // �������� ������� ���������
	LPARAM lParam) // �������� ������� ���������
{
	switch (uMsg)
	{
		case WM_PAINT:
		{
			// ����� ����� ��������� �������� ���������� ����, � ����. ���������������� �������
			break;
		}

		case WM_CREATE:
		{
			// ����� ����� ��������� �������� ���������� ����
			break;
		}

		case WM_PARENTNOTIFY:
		{
			// ����� ����� ��������� �������� ���������� ��������� ����
			break;
		}


		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
				// ��������� ������ (������� ������, ����, ����� ����� � �.�.)
			case 100:
				{
					MessageBox(hwnd, L"100", L"100", MB_ICONERROR);
					break;
				}
			case 101:
			{
				MessageBox(hwnd, L"101", L"101", MB_ICONERROR);
				break;
			}
			}
			break;
		}

		case WM_DESTROY: // ��������� ������� ������ �������� ����
		{
			// ������� ������� ����
			PostQuitMessage(0);
			return 0;
			break;
		}

		case WM_KEYUP:
		{
			switch (wParam)
			{
				case VK_ESCAPE:
				{
					PostQuitMessage(0);
				}
				break;
			}	
			break;
		} 
		//break;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
