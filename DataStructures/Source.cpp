#include "Header.h"

void StackPresentation();
void QueuePresentation();
void DynamicArrayPresentation();
void SinglyLinkedListPresentation();
void DoublyLinkedListPresentation();
void BinaryTreePresentation();

int main()
{
	//StackPresentation();
	//QueuePresentation();
	DynamicArrayPresentation();
	//SinglyLinkedListPresentation();
	//DoublyLinkedListPresentation();
	//BinaryTreePresentation();

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

void DynamicArrayPresentation()
{
	DynamicArrayDemo::DynamicArr<int> d;

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);

	for (size_t i = 0; i < d.size(); i++)
		cout << d[i] << " | ";

	d.remove(1);
	
	cout << endl;

	for (size_t i = 0; i < d.size(); i++)
		cout << d[i] << " | ";

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

void DoublyLinkedListPresentation()
{
	DoublyLinkedListDemo::DoublyLinkedList<int> d;

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.remove_by_index(3);
	d.push_front(19);

	DoublyLinkedListDemo::DoublyLinkedList<int> c;

	c.push_back(110);
	c.swap(d);

	for (size_t i = 0; i < c.size(); i++)
		cout << c[i] << ", ";
}   

void BinaryTreePresentation()
{
	BinaryTreeDemo::BinTree<string, int> d;

	d.Add("123239829", 2142);
	d.Add("123211240", 2203);
	d.Add("000000001", 9999);

	cout << "Size: " << d.Size() << endl << d["123239829"] << endl;

	d.Remove("123239829");

	cout << "Size: " << d.Size() << endl;
}