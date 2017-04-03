// Создаем окно при помощи шаблона
// Visual Studio C++ WinApi

// Подключаем библиотеки Windows для Win32
#include <windows.h>

// Объявляем прототип CALLBACK функции
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Функция WinAPI для точки входа в программу
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// Регистрация класса окна
	// Объявляем переменную типа WNDCLASSEX

	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(WNDCLASSEX)); // Обнуляем память

											 // Заполняем структуру WNDCLASSEX
	wClass.cbSize = sizeof(WNDCLASSEX); // Размер равен размеру структуры
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW; // Определяем фон окна
	wClass.hInstance = hInstance; // hInstance window
	wClass.lpfnWndProc = (WNDPROC)WndProc; // Процедура обработки окна
	wClass.lpszClassName = L"My Window Class"; // Имя класса


											  // Если произошла ошибка, то выводим сообщение
	if (!RegisterClassEx(&wClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"Класс окна не был создан!", L"Ошибка", MB_ICONERROR);
	}

	// Создаем окно при помощи функции WinApi CreateWindowEx
	HWND hWindow = CreateWindowEx(NULL,
		L"My Window Class", // Имя класса, который мы определили ранее
		L"Мое первое окно с WinApi", // Заголовок окна
		WS_OVERLAPPEDWINDOW,
		300, // x координата по горизонтали
		200, // y координата по вертикали
		640, // ширина создаваемого окна
		480, // высота создаваемого окна
		NULL,
		NULL,
		hInstance, // переменная экземпляра приложения
		NULL);

	// Если окно не было создано, то выдаем сообщение
	if (!hWindow)
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"Окно не было создано!", L"Ошибка", MB_ICONERROR);
	}

	// Показываем окно
	ShowWindow(hWindow, nShowCmd);

	// Объявляем переменную для сообщений типа MSG
	MSG msg;
	// Обнуляем память по размеру структуры MSG
	ZeroMemory(&msg, sizeof(MSG));

	// Цикл обработки сообщений
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

// определяем процедуру обратного вызова (WinApi)

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
		{
			// Здесь будем создавать элементы управления окна
			break;
		}

		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
				// Обработка команд (нажатие кнопок, мыши, полей ввода и т.д.)
			}

			break;
		}

		case WM_DESTROY: // Обработка нажатия кнопки закрытия окна
		{
			// команда Закрыть окно
			PostQuitMessage(0);
			return 0;
			break;
		}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
