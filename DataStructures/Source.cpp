#include "Header.h"

void StackPresentation();
void QueuePresentation();
void SinglyLinkedListPresentation();
void DoublyLinkedListDemoPresentation();

int main()
{
	//StackPresentation();
	//QueuePresentation();
	//SinglyLinkedListPresentation();
	DoublyLinkedListDemoPresentation();

	return 0;
}

void StackPresentation()
{
	StackDemo::Stack<int> data1;
	StackDemo::Stack<int> data2;

	data1.push(1);
	data1.push(2);
	data1.push(3);

	data2.push(4);
	data2.push(5);
	data2.push(6);
	data2.push(7);

	data1.pop();

	for (size_t i = 0; i < data1.size(); i++)
	{
		cout << data1[i];
	}
}

void QueuePresentation()
{
	QueueDemo::Queue<int> data1;

	data1.push(1);
	data1.push(2);
	data1.push(3);

	cout << data1.front() << " " << data1.back();
}

void SinglyLinkedListPresentation()
{
	SinglyLinkedListDemo::SinglyLinkedList<int> d;
	SinglyLinkedListDemo::SinglyLinkedList<int> c;


	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(4);

	c.push_back(5);
	c.push_back(6);
	c.push_back(7);
	c.push_front(8);

	for (size_t i = 0; i < d.size(); i++)
		cout << d[i] << " | ";

	d.remove_by_index(0);

	cout << endl;
	for (size_t i = 0; i < d.size(); i++)
		cout << d[i] << " | ";
}

void DoublyLinkedListDemoPresentation()
{
	DoublyLinkedListDemo::DoublyLinkedList<int> d;

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_front(19);

	for (size_t i = 0; i < d.size(); i++)
		cout << d[i] << ", ";
}