// Создаем окно при помощи шаблона
// Visual Studio C++ WinApi

// Подключаем библиотеки Windows для Win32
#include <windows.h>

// Объявляем прототип CALLBACK функции
LRESULT CALLBACK MainWindowClassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Функция WinAPI для точки входа в программу
int WINAPI WinMain(
	HINSTANCE hInstance,		//handle к текущему экземпляру приложения
	HINSTANCE hPrevInstance,	//handle к предыдущему экземпляру приложения
	LPSTR lpCmdLine,			//адрес командной строки
	int nShowCmd)				//тип окна
{
	// Регистрация класса окна
	// Объявляем переменную типа WNDCLASSEX

	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(WNDCLASSEX)); // Обнуляем память

	// Заполняем структуру WNDCLASSEX
	wClass.style = CS_HREDRAW | CS_VREDRAW; //Стиль окна
	wClass.lpfnWndProc = (WNDPROC)MainWindowClassProc; // Процедура обработки окна
	wClass.hInstance = hInstance; // hInstance window
	wClass.cbSize = sizeof(WNDCLASSEX); // Размер равен размеру структуры
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW; // Определяем фон окна
	wClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);	
	wClass.lpszMenuName = L"MainMenu"; //Имя меню
	wClass.lpszClassName = L"MainWindowClass"; // Имя класса


	// Если произошла ошибка, то выводим сообщение
	if (!RegisterClassEx(&wClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"Класс окна не был создан!", L"Ошибка", MB_ICONERROR);
	}

	// Создаем окно при помощи функции WinApi CreateWindowEx
	HWND hWindow = CreateWindowEx(NULL,
		L"MainWindowClass", // Имя класса, который мы определили ранее
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

LRESULT CALLBACK MainWindowClassProc(
	HWND hwnd,     // handle окна
	UINT uMsg,     // идентификатор сообщения
	WPARAM wParam, // параметр первого сообщения
	LPARAM lParam) // параметр второго сообщения
{
	switch (uMsg)
	{
		case WM_PAINT:
		{
			// Здесь будем создавать элементы заполнения окна, к прим. пользовательскую область
			break;
		}

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
