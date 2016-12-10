#include <iostream>

using namespace std;

class MyClass {
public:
	int x;
	char c;
	//MyClass();
	//MyClass(int aLen, char aChar); //����������� �����������
	//MyClass(MyClass & other); //����������� ����������� � ���������
	void display(MyClass *aObj);

//����������� ����������� �� ���������
	MyClass() :
		//�������������� ��������;
		x(0), c(' ')
	{}

//����������� ����������� c �����������
	MyClass(int aLen, char aChar) :
		//�������������� ��������;
		x(aLen), c(aChar)
	{}

//����������� ����������� � ���������� ����� �������
	MyClass(MyClass &other) :
		x((other.x) + 1), c((other.c) + 1)
	{}


};

void display(MyClass *aObj) {
	std::cout << "MyClass int is: " << aObj->x << std::endl;
	std::cout << "MyClass char is: " << aObj->c << std::endl;
}


int main() {

	MyClass a = MyClass();
	display(&a);

	MyClass b = MyClass(1000, 'B');
	display(&b);

	MyClass c = MyClass(b);
	display(&c);
	display(&b);
}