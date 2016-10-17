#include <stdio.h>
#include <cstdio>
#include <iostream>

using namespace std;

/* ¬ариант N6.
«адан одномерный массив ’ вещественных чисел.
Ќайти произведение чисел, составл€ющих наиболее длинную непрерывную последовательность элементов,
не содержащую 0.
*/

//русский  
int main() {
	//double massiv[9]={1, 0, 2, 3, 0, 5, 6, 7, 0}; //заданный массив
	double massiv[11] = { -222, 1, -2, 110, 0, 0, 2, 4, 4, 31, 2 };
	double m = 0;
	int i, j, n = 0; //счетчики
	int indexstart = 0, indexend = 0; //индексы
	int nmax = 0; //наиболе длинна€ непрерывна€ последовательность элементов
				  //double s = massiv[0] * massiv[1]; //произведение первых 2 чисел
				  //printf("The initial multiplication S is: %9.3lf\n", s);

				  //внешний цикл выполн€етс€ до первого вхождени€ 0
	for (i = 0; i < 11; i++) {
		if (massiv[i] != 0) {
			//начнем отсчет счетчика не нулевых элементов
			n = 1;
			//обновим счетчики в св€зи со стартом отсчета
			if (nmax < n) {
				nmax = n; //наиболее длинна€ последовательность увеличилась	
				indexstart = i; //запомним индекс первого элемента
				indexend = i; //запомним индекс последнего элемента
			};
			//внутренний цикл дл€ прохода от первого не нулевого элемента до следующего нулевого
			for (j = i + 1; j < 11; j++) {
				if (massiv[j] == 0) {
					i = j; //передвинем индекс на следующий нулевой элемент
					break; //выйдем из цикла
				}
				else n = n + 1;  //увеличим счетчик				  
				if (nmax < n) {
					nmax = n; //наиболее длинна€ последовательность увеличилась	
					indexstart = i; //запомним индекс первого элемента
					indexend = j; //запомним индекс последнего элемента
				};
			};
		};
	};
	//определив indexstart и indexend самой длинной непрер≥вной последовательности без 0
	//в≥полним подсчет произведени€
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