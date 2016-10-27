#include <iostream> 
#include <locale>
#include <cstring>
#include "List.h"

using namespace std;

int main()
{
	//List<int>* a = new List<int> ;
	List<int> a;
	cout << a.size() << endl;
	a.insertToEnd(1);
	a.insertToEnd(-1);
	a.insertToEnd(0);

/*
	a.insertNode(3);
	a.insertNode(2);
	a.insertNode(-1);
	a.insertNode(0);
*/
	cout << a.size() << endl;
	//a.print(); //распечатаем List
	

	a.clear();
	cout << a.size() << endl;
	int sleep; cin >> sleep;
}
