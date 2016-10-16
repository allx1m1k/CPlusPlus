#include <stdio.h>
#include <cstdio>
#include <iostream>

using namespace std;
  
/* Вариант N6.
Задана матрица А(6,6) вещественных чисел. Если какой-либо столбец матрицы, кроме первого и последнего, содержит все “1”,
то заменить каждую “1” на сумму соседних в соответствующей строке элементов. Поиск столбца со всеми “1” организовать в подпрограмме.
*/

//Как передать в функцию указатель http://itedu.ru/faq/kak-peredat-v-funkciyu-staticheskiy-dvumernyy-massiv-v-c
//функция проверки колонки по 2-м индексам
bool check2D(double a[][6], int row, int column);
//функция проверки колонки по смещению указателя, работа с адресной арифметикой
bool checkPointer(double *a, int row, int column);
//функция подсчета значений 
void calc(double *a, int row, int column);



int main() {
	//заданный массив
	double massiv[6][6] = {
		{ 0, 1, 0, 0, 1, 0 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 0, 0, 1, 0 }
	};
	//строка, колонка
	int row = 0, col = 2;
	//флаг используется для отбора колонки со всеми единицами
	bool flag = false;

	//начнем проход по колонкам со второй по пятую по условию задачи
	for (col = 1; col < 5; col++) {
		//вызовем функцию проверки колонки на все 1 единицы передав в нее указатель на матрицу
		//flag = checkPointer((double *)massiv, row, col);
		//вызовем функцию проверки колонки на все 1 единицы передав в нее индексы
		flag = check2D(massiv, row, col);
		printf("Column %d is matched yes-1, no-0  - %d\n", col, flag);
		printf("\n");
		//рассчитаем сумму соседних с колонкой элементов только в случае поднятого флага
		if (flag) {
			printf("New valuse of elements are: \n");
			calc((double *)massiv, row, col);
			printf("\n");
		}
	}
	system("pause");
	return 0;
}

//функция проверки колонки на содержание 1
//принимаем указатель индексы строки и колонки
bool check2D(double a[][6], int row, int column) {
	int index = 0;
	bool flag = false;
	for (index = row; index < 6; index++) {
		//проверим значение элемента
		if (a[index][column] == 1) {
			//проверим позицию в колонке, прошлись ли по всем рядам?
			if (index == 5) {
				flag = true;
			}
		}
		else break;
	}
	return flag;
}

//функция проверки колонки на содержание 1
//принимаем указатель на массив
bool checkPointer(double *a, int row, int column) {
	int index = 0;
	bool flag = false;
	for (index = row; index < 6; index++) {
		//адресная арифметика и разименование т.е. работа со значением по указателю		
		//проверим значение элемента
		if (*(a + index * 6 + column) == 1) {
			//проверим позицию в колонке, прошлись ли по всем рядам?
			if (index == 5) {
				flag = true;
			}
		}
		else break;
	}
	return flag;
}
//функция полсчета нового значения путем суммирования значений 2ух элементов в колонке по левую сторону и по правую сторону
void calc(double *a, int row, int column) {
	int index = 0;
	double summa = 0;
	//адресная арифметика и разименование т.е. работа со значением по указателю		
	//проверим значение элемента
	for (index = row; index < 6; index++) {
		summa = *(a + index * 6 + (column - 1)) + *(a + index * 6 + (column + 1));
		printf("%9.3lf", summa);
		printf("\n");
	}
}


