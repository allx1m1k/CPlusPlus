#include <stdio.h>
#include <cstdio>
#include <iostream>

using namespace std;


/*Вариант 6
задан одномерный массив Х вещественных чисел
Найти произведение чисел, составляющих наиболее длинную последоватьность элементов,
не содержащуую 0.
*/

//русский
/*
int main() {
	//double massiv[9]={1, 0, 2, 3, 0, 5, 6, 7, 0}; //массив
	double massiv[11] = { -222, 1, -2, 110, 0, 0, 2, 4, 4, 31, 2 };
	double m = 0;
	int i, j, n = 0; //счетчики
	int indexstart = 0, indexend = 0; //индексы
	int nmax = 0; //ниболее длинная непрерывная последовательность элементов
				  //double s = massiv[0] * massiv[1]; //
				  //printf("The initial multiplication S is: %9.3lf\n", s);

				  //внешний цикл выполняется до первого вхождения 0
	for (i = 0; i < 11; i++) {
		if (massiv[i] != 0) {
			//начнем отсчет счетчика не нулевых эл-ов
			n = 1;
			//обновим счетчики в сязи со стартом отсчета
			if (nmax < n) {
				nmax = n; //наиболее длинная последовательность увеличилась
				indexstart = i; //запомним индекс первого эл-та
				indexend = i; //запомним индекс последнего эл-та
			};
			//внутренний цикл для прохода от первого не нулевого эл-та до следующего нулевого
			for (j = i + 1; j < 11; j++) {
				if (massiv[j] == 0) {
					i = j; //передвинем индекс на след. нулевой эл-т
					break; //выйдем из цикла
				}
				else n = n + 1;  //увеличим счетчик
				if (nmax < n) {
					nmax = n; //наиболее длинная послед-ть увеличилась
					indexstart = i; //запомним индекс первого эл-та
					indexend = j; //запомним индекс последнего эл-та
				};
			};
		};
	};
	//определив indexstart и indexend самой длиной последо-ти без 0
	//выполним подсчет произведения
	for (int k = indexstart; k < indexend + 1; k++) {
		if (m == 0)
			m = massiv[k];
		else
			m = m * massiv[k];
	}
	//выведем все результаты
	printf("Nmax is: %d\n", nmax);
	printf("N is: %d\n", n);
	printf("I Index start is: %d\n value is %9.3lf\n ", indexstart, massiv[indexstart]);
	printf("J Index end is: %d\n value is %9.3lf\n ", indexend, massiv[indexend]);
	printf("Multiplication is: %9.3lf\n ", m);
	system("pause");
	return 0;
}
*/

/*
#include <iostream>

int main()
{
size_t length	  = 0;
size_t max_length = 0;

double value;
double production		= 0;
double max_production	= 0;

while (std::cin >> value)
{
if (0 == value)
{
if (length > max_length)
{
max_length 		= length;
max_production 	= production;
}

length 	   = 0;
production = 0;
}
else
{
length++;
production = (0 == production) ? value : production * value;
}
}

std::cout << "max length: " << max_length << std::endl;
std::cout << "max production: " << max_production << std::endl;

return 0;
}
*/