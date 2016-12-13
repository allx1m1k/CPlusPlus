#include <iostream> 
#include <locale>
#include <cstring>
#include "List.h"

using namespace std;

int main()
{
	List<int> a;
	cout << a.size() << endl;
	a.insertToEnd(-1);
	a.insertToEnd(11);
	a.insertToEnd(100);
	a.insertToEnd(0);
	a.insertToEnd(1);

	cout << a.size() << endl;
	a.print(); //распечатаем List
	

	a.clear();
	cout << a.size() << endl;
	a.print(); //распечатаем List
	int sleep; cin >> sleep;
}
