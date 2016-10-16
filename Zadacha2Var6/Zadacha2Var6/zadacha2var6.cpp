#include <stdio.h>
#include <cstdio>
#include <iostream>

using namespace std;
  
/* ������� N6.
������ ������� �(6,6) ������������ �����. ���� �����-���� ������� �������, ����� ������� � ����������, �������� ��� �1�,
�� �������� ������ �1� �� ����� �������� � ��������������� ������ ���������. ����� ������� �� ����� �1� ������������ � ������������.
*/

//��� �������� � ������� ��������� http://itedu.ru/faq/kak-peredat-v-funkciyu-staticheskiy-dvumernyy-massiv-v-c
//������� �������� ������� �� 2-� ��������
bool check2D(double a[][6], int row, int column);
//������� �������� ������� �� �������� ���������, ������ � �������� �����������
bool checkPointer(double *a, int row, int column);
//������� �������� �������� 
void calc(double *a, int row, int column);



int main() {
	//�������� ������
	double massiv[6][6] = {
		{ 0, 1, 0, 0, 1, 0 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 0, 0, 1, 0 }
	};
	//������, �������
	int row = 0, col = 2;
	//���� ������������ ��� ������ ������� �� ����� ���������
	bool flag = false;

	//������ ������ �� �������� �� ������ �� ����� �� ������� ������
	for (col = 1; col < 5; col++) {
		//������� ������� �������� ������� �� ��� 1 ������� ������� � ��� ��������� �� �������
		//flag = checkPointer((double *)massiv, row, col);
		//������� ������� �������� ������� �� ��� 1 ������� ������� � ��� �������
		flag = check2D(massiv, row, col);
		printf("Column %d is matched yes-1, no-0  - %d\n", col, flag);
		printf("\n");
		//���������� ����� �������� � �������� ��������� ������ � ������ ��������� �����
		if (flag) {
			printf("New valuse of elements are: \n");
			calc((double *)massiv, row, col);
			printf("\n");
		}
	}
	system("pause");
	return 0;
}

//������� �������� ������� �� ���������� 1
//��������� ��������� ������� ������ � �������
bool check2D(double a[][6], int row, int column) {
	int index = 0;
	bool flag = false;
	for (index = row; index < 6; index++) {
		//�������� �������� ��������
		if (a[index][column] == 1) {
			//�������� ������� � �������, �������� �� �� ���� �����?
			if (index == 5) {
				flag = true;
			}
		}
		else break;
	}
	return flag;
}

//������� �������� ������� �� ���������� 1
//��������� ��������� �� ������
bool checkPointer(double *a, int row, int column) {
	int index = 0;
	bool flag = false;
	for (index = row; index < 6; index++) {
		//�������� ���������� � ������������� �.�. ������ �� ��������� �� ���������		
		//�������� �������� ��������
		if (*(a + index * 6 + column) == 1) {
			//�������� ������� � �������, �������� �� �� ���� �����?
			if (index == 5) {
				flag = true;
			}
		}
		else break;
	}
	return flag;
}
//������� �������� ������ �������� ����� ������������ �������� 2�� ��������� � ������� �� ����� ������� � �� ������ �������
void calc(double *a, int row, int column) {
	int index = 0;
	double summa = 0;
	//�������� ���������� � ������������� �.�. ������ �� ��������� �� ���������		
	//�������� �������� ��������
	for (index = row; index < 6; index++) {
		summa = *(a + index * 6 + (column - 1)) + *(a + index * 6 + (column + 1));
		printf("%9.3lf", summa);
		printf("\n");
	}
}


