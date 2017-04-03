// ������� ���� ��� ������ �������
// Visual Studio C++ WinApi

// ���������� ���������� Windows ��� Win32
#include <windows.h>

// ��������� �������� CALLBACK �������
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// ������� WinAPI ��� ����� ����� � ���������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// ����������� ������ ����
	// ��������� ���������� ���� WNDCLASSEX

	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(WNDCLASSEX)); // �������� ������

											 // ��������� ��������� WNDCLASSEX
	wClass.cbSize = sizeof(WNDCLASSEX); // ������ ����� ������� ���������
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW; // ���������� ��� ����
	wClass.hInstance = hInstance; // hInstance window
	wClass.lpfnWndProc = (WNDPROC)WndProc; // ��������� ��������� ����
	wClass.lpszClassName = L"My Window Class"; // ��� ������


											  // ���� ��������� ������, �� ������� ���������
	if (!RegisterClassEx(&wClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"����� ���� �� ��� ������!", L"������", MB_ICONERROR);
	}

	// ������� ���� ��� ������ ������� WinApi CreateWindowEx
	HWND hWindow = CreateWindowEx(NULL,
		L"My Window Class", // ��� ������, ������� �� ���������� �����
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

	// ���������� ����
	ShowWindow(hWindow, nShowCmd);

	// ��������� ���������� ��� ��������� ���� MSG
	MSG msg;
	// �������� ������ �� ������� ��������� MSG
	ZeroMemory(&msg, sizeof(MSG));

	// ���� ��������� ���������
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

// ���������� ��������� ��������� ������ (WinApi)

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
		{
			// ����� ����� ��������� �������� ���������� ����
			break;
		}

		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
				// ��������� ������ (������� ������, ����, ����� ����� � �.�.)
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
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
