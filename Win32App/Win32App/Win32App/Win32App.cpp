//Sync with note
// Создаем окно при помощи шаблона
// Visual Studio C++ WinApi

// Подключаем библиотеки Windows для Win32
#include <windows.h>
#include <winuser.h>
#include <tchar.h>

// 
PAINTSTRUCT ps;
HDC hdc;
TCHAR greeting[] = L"Студент ПАМ-152. Пельтик Д.В.";

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
	wClass.lpszClassName = L"MainWindowClass"; // Имя класса


	// Если произошла ошибка, то выводим сообщение
	if (!RegisterClassEx(&wClass))
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"Класс окна не был создан!", L"Ошибка", MB_ICONERROR);
	}

	// Создаем окно при помощи функции WinApi CreateWindowEx, получаем handle к окну
	HWND hWindow = CreateWindowEx(NULL,
		//L"MainWindowClass", 
		wClass.lpszClassName, // Имя класса, который мы определили ранее при регистрации окна
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

	//тут был вызов показа окна

	// Объявляем переменную для сообщений типа MSG
	MSG msg;
	// Обнуляем память по размеру структуры MSG
	ZeroMemory(&msg, sizeof(MSG));

	// создаем меню бар
	HMENU hMenuBar = CreateMenu();
	//HMENU hMenuBar = GetMenu(hWindow);
	
	// Если меню не было создано, то выдаем сообщение
	if (!hMenuBar)
	{
		int nResult = GetLastError();
		MessageBox(NULL, L"Меню не было создано!", L"Ошибка создания меню", MB_ICONERROR);
	}

	// Добавляем опции меню
	AppendMenu(
		hMenuBar,
		MFT_STRING | MF_POPUP,
		100, //сообщение при клике
		L"Таймер");

	AppendMenu(
		hMenuBar,
		MFT_STRING | MF_POPUP,
		101, //сообщение при клике
		L"Графики");

	AppendMenu(
		hMenuBar,
		MFT_STRING | MF_POPUP,
		102, //сообщение при клике
		L"Автор");

	AppendMenu(
		hMenuBar,
		MFT_STRING | MF_POPUP,
		103, //сообщение при клике
		L"Реестр");

	/*
	InsertMenuItem(
		hMenuBar,	// handle меню
		1,			// начальная позиция меню
		TRUE,		// интерпритировать опции меню как позиции а не наименования
		NULL);		// ссылка MENUITEMINFO
	*/

	// Показываем окно и рисуем вместе с меню
	SetMenu(hWindow, hMenuBar);
	DrawMenuBar(hWindow);	
	ShowWindow(hWindow, nShowCmd);
	
				
	// Цикл обработки сообщений
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
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
			hdc = BeginPaint(hwnd, &ps);

			// Here your application is laid out.  
			// For this introduction we print in greeting the top left corner.  
			TextOut(hdc, 5, 5, greeting, _tcslen(greeting));
			// End application-specific layout section.  

			EndPaint(hwnd, &ps);
			break;
		}

		case WM_CREATE:
		{
			// Здесь будем создавать элементы управления окна
			break;
		}

		case WM_PARENTNOTIFY:
		{
			// Здесь будем создавать элементы управления дочернего окна
			break;
		}


		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
				// Обработка команд (нажатие кнопок, мыши, полей ввода и т.д.)
			case 100:
				{
					MessageBox(hwnd, L"Таймер", L"100", MB_ICONINFORMATION);
					break;
				}
			case 101:
				{
					MessageBox(hwnd, L"Графики", L"101", MB_ICONERROR);
					break;
				}
			case 102:
				{
					MessageBox(hwnd, L"Автор", L"102", MB_ICONERROR);
					break;
				}
			case 103:
			{
				MessageBox(hwnd, L"Реестр", L"103", MB_ICONERROR);
				break;
			}


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
