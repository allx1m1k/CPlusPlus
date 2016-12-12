#pragma once
/* Модель 2-х связанного списка
*/
template<class T> class List
{ //описание List
public:
	List();  //конструктор List п.у.
	List(int number);  //конструктор List с указанным кол-ом Nodes
	~List(); //деконструктор List п.у.

	struct Node // Структурный тип для элемента списка
	{

		T mData;  //типизированные (шаблонные) данные, хранящиеся в узле
		Node* prior; //указатель на предыдущий элемент
		Node* next;  //указатель на следующий элемент

		Node() : //конструктор
			mData(0),
			prior(nullptr),
			next(nullptr)
		{}
	};

	//описание API интерфейса к списку
	Node* nextNode();
	Node* prevNode();
	Node* insertNode(T data);
	Node* insertAfterNode(Node* n, T data);  //вставить новый нод data, после нода n
	Node* insertToEnd(T data); //pushback	
								//Node* getNewNode(const T&); 
	int size();
	void clear();
	void sort();
	void print();
	bool isEmpty();


private: //стуктура Списка
	int count; //кол-во элементов
	Node* head; //первый нод
	Node* tail; //последний нод		
}; //конец описания List


   //реализация конструктора/деструктора List
template<class T> //параметризированный конструктор
List<T>::List()
	:count(0)
	, head(nullptr)
	, tail(nullptr)
{
}

template<class T> //перегрузка конструктора
List<T>::List(int numberOfNodes)
	:count(numberOfNodes)
	, head(0)
	, tail(0)
{
	(count = numberOfNodes);
}

template<class T> //параметризированный деструктор
List<T>::~List()
{
}

//реализация API List
template<class T>
int List<T>::size()
{
	return count;
}

template<class T>
void List<T>::clear()
{

	Node* i = head; //получим указатель на первую ноду
	while (i != 0) //пока указатель содержит хоть какой-то адрес
	{
		Node* tmp = i; //сохраним текущий адрес во временную переменную
		i = i->next; //определим адрес следующей ноды
		delete tmp; //удалим ноду по адресу временной переменной
	}
	count = 0; //обнулим внутренний счетчик кол-ва нод

}


template<class T>
bool List<T>::isEmpty()
{
	return size();

}


template<class T>
typename List<T>::Node* List<T>::insertNode(T data)
{
	List<T>::Node* nNode = new Node; //выделм место в памяти
	nNode->mData = data; //из-под указателя, во внутренний атрибут запишем значение формального аргумента
	head = nNode;
	tail = nNode;
	count++; //увеличим счетчик

	return nNode;
}

template<class T>
typename List<T>::Node* List<T>::insertToEnd(T data)
{ //pushback
	List<T>::Node* nNode = new Node; //выделим место в памяти, установим указатель на первую ячейку
	nNode->mData = data; //из-под указателя, во внутренний атрибут запишем значение формального аргумента
	if (count == 0) //если список пуст
	{
		head = nNode; //начало Lista указывает на вновь созданны	 Node
		tail = nNode; //конец Lista указывает на вновь созданны	 Node
					  //data->next = 0;
					  //data->prior = 0;
	}
	else //если список не пуст: 
	{ 
		 //1. в новый Node указатель на предыдущий Node prior установим равным хвосту (tail)
		 //1.1.  в новый Node указатель на следующий Node next установим равным 0
		 //2. в хвостовом Node Lista перекинем указатель next на новый Node
		 //3. перекинем конец Listа tail на новый Node		
		nNode->prior = tail; //п.1
		nNode->next = 0; //п.1.1
		tail->next = nNode;//п.2
		tail = nNode; //п.3
	}
	cout << "adding " << data << endl;
	count++; //увеличим счетчик
	return nNode;
} //end pushback

//print
template<class T>
void List<T>::print()
{

	if (size() > 0) //выведем Node на экран только если List не пустой
	{
		Node* i = head; //получим указатель на первую ноду
		while (i->next != nullptr) //пока Node содержит указатель на next Node
		{
			//Node* tmp = i; //сохраним текущий адрес во временную переменную
			std::cout << "Current node is: " << i->mData << " Next node is:" << i->next->mData << std::endl;
			i = i->next;
		}
	} else 
		cout << "The List is empty \n";
}


  /*
  template<class T>
  List<T>::getNewNode(Node node)
  {
  return Node* node;
  }
  */





