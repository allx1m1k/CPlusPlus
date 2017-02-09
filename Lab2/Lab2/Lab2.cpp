#include <iostream> 
#include <locale>
#include <cstring>



using namespace std;

class MyClass {
public:
	int x;
	char c;
	//MyClass();
	//MyClass(int aLen, char aChar); //стандартный конструктор
	//MyClass(const MyClass & other); //конструктор копирования и изменения
	void display(MyClass *aObj);

//стандартный конструктор по умолчанию
	MyClass() :
		//инициализируем значения;
		x(0), c(' ')
	{
		std::cout << "Creating instance with empty attributes" << std::endl;
	}

//стандартный конструктор c параметрами
	MyClass(int aLen, char aChar) :
		//инициализируем значения;
		x(aLen), c(aChar)
	{
		std::cout << "Creating instance with predefined attributes" << std::endl;
	}

//конструктор копирования с изменением полей объекта
	MyClass(const MyClass &other) :
		x((other.x) + 1), c((other.c) + 1)
	{
		std::cout << "Creating the copy and changing the attributes" << std::endl;
	}


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