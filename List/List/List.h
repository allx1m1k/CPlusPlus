#pragma once
/* ������ 2-� ���������� ������
*/
template<class T> class List
{ //�������� List
public:
	List();  //����������� List �.�.
	List(int number);  //����������� List � ��������� ���-�� Nodes
	~List(); //������������� List �.�.

	struct Node // ����������� ��� ��� �������� ������
	{

		T* mData;  //������, ���������� � ����
		Node* prior; //��������� �� ���������� �������
		Node* next;  //��������� �� ��������� �������

		Node() : //�����������
			mData(0),
			prior(0),
			next()
		{}
	};

	//�������� API ���������� � ������
	Node* nextNode();
	Node* prevNode();
	Node* insertNode(T data);
	Node* insertAfterNode(Node* n, T data);  //�������� ����� ��� data, ����� ���� n
	Node* insertToEnd(T* data); //pushback	
								//Node* getNewNode(const T&); 
	int size();
	void clear();
	void sort();
	void print();
	bool isEmpty();


private: //�������� ������
	int count; //���-�� ���������
	Node* head; //������ ���
	Node* tail; //��������� ���		
}; //����� �������� List


   //���������� ������������/����������� List
template<class T> //������������������� �����������
List<T>::List()
	:count(0)
	, head(0)
	, tail(0)
{
}

template<class T> //���������� ������������
List<T>::List(int numberOfNodes)
	:count(numberOfNodes)
	, head(0)
	, tail(0)
{
	(count = numberOfNodes);
}

template<class T> //������������������� ����������
List<T>::~List()
{
}

//���������� API List
template<class T>
int List<T>::size()
{
	return count;
}

template<class T>
void List<T>::clear()
{

	Node* i = head; //������� ��������� �� ������ ����
	while (i != 0) //���� ��������� �������� ���� �����-�� �����
	{
		Node* tmp = i; //�������� ������� ����� �� ��������� ����������
		i = i->next; //��������� ����� ��������� ����
		delete tmp; //������ ���� �� ������ ��������� ����������
	}
	count = 0; //������� ���������� ������� ���-�� ���

}


template<class T>
bool List<T>::isEmpty()
{
	return size();

}


template<class T>
typename List<T>::Node* List<T>::insertNode(T data)
{
	List<T>::Node* nNode = new Node; //������� ����� � ������
	nNode->mData = &data; //� ��������� �� ���������� ������� ������� �����
	count++; //�������� �������

	head = nNode;
	tail = nNode;

	return nNode;
}

template<class T>
typename List<T>::Node* List<T>::insertToEnd(T* data)
{ //pushback
	List<T>::Node* nNode = new Node; //������� ����� � ������
	nNode->mData = data; //� ��������� �� ���������� ������� �������� ����� ����������� ���������
	count++; //�������� �������
	if (count == 0) //���� ������ ����
	{
		head = nNode; //������ Lista ��������� �� ����� ��������	 Node
		tail = nNode; //����� Lista ��������� �� ����� ��������	 Node
					  //data->next = 0;
					  //data->prior = 0;
	}
	else //���� ������ �� ����: 
		 //1. � ����� Node ��������� �� ���������� Node prior ��������� ������ ������ (tail)
		 //1.1.  � ����� Node ��������� �� ��������� Node next ��������� ������ 0
		 //2. � ��������� Node Lista ��������� ��������� next �� ����� Node
		 //3. ��������� ����� List� tail �� ����� Node		
		nNode->prior = tail; //�.1
	nNode->next = 0; //�.1.1
	tail->next = nNode;//�.2
	tail = nNode; //�.3

	return nNode;
} //end pushback


  /*
  template<class T>
  List<T>::getNewNode(Node node)
  {
  return Node* node;
  }
  */




