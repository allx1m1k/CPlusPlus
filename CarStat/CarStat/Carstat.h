#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>

/*
»меетс€ файл, в каждой строке которого хранитс€ запись о проданном авто.
Ќеобходимо вывести на экран информацию о самом дорогом проданном авто,
год выпуска которого не старше заданного.
*/


//.в с++11 встроен удобный api дл€ работы с файлами - используй его
//https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
//fstream https://msdn.microsoft.com/en-us/library/k8w40w6t.aspx
//. вычитка структуры из файла http://ci-plus-plus-snachala.ru/?p=2177
//.по-сточна€ вычитка из файла по условию (год выпуска <= заданный год)
//см. тут http://www.cplusplus.com/forum/beginner/208388/#msg982326
//. вычитка в буфер http://www.programmersforum.ru/showthread.php?t=91445
//запись считанной строки в несортированную динамическую структуру-контейнер
//см. stl контейнеры http://informatics.mccme.ru/mod/book/view.php?id=492&chapterid=200
//. сортировка динамических контейнеров http://www.cplusplus.com/articles/NhA0RXSz/ 


struct Car
{
	std::string brandName; //бренд
	float price; //цена
	uint16_t year; //год выпуска
};