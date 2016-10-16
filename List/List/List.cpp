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
	a.insertNode('Dima');
	a.insertNode(1);
	a.insertNode(3);
	cout << a.size() << endl;

	a.clear();
	cout << a.size() << endl;

	a.insertToEnd(new int(1));
	a.insertToEnd(new int(2));
	cout << a.size() << endl;
	a.clear();
	cout << a.size() << endl;

	int sleep; cin >> sleep;
}
