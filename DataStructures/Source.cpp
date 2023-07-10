#include "Header.h"

//
// * Data structure(data structure).It is a way of combining and interacting data elements.
// *
// * The data structure plays an important role in the programming and operation of programs.
// * Different data structures can be applied in different scenarios depending on the robustness and 
// * characteristics of the task.
// *
//

void StackTest();
void QueueTest();
void DynamicArrayTest();
void SinglyLinkedListTest();
void DoublyLinkedListTest();
void BinaryTreeTest();

int main()
{
	StackTest();
	QueueTest();
	DynamicArrayTest();
	SinglyLinkedListTest();
	DoublyLinkedListTest();
	BinaryTreeTest();

	return 0;
}

#pragma region Tests.
void StackTest()
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

void QueueTest()
{
	QueueDemo::Queue<int> data1;

	data1.push(1);
	data1.push(2);
	data1.push(3);

	cout << data1.front() << " " << data1.back();
}

void DynamicArrayTest()
{
	DynamicArrayDemo::DynamicArr<int> d;

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.insert(1, 22);

	DynamicArrayDemo::DynamicArr<int> c;

	c.push_back(33);
	c.push_back(33);
	c.push_back(33);

	d.swap(c);

	for (size_t i = 0; i < d.size(); i++)
		cout << d[i] << " | ";


	cout << endl;

	for (size_t i = 0; i < c.size(); i++)
		cout << c[i] << " | ";
}

void SinglyLinkedListTest()
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

void DoublyLinkedListTest()
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

void BinaryTreeTest()
{
	BinaryTreeDemo::BinTree<string, int> d;

	d.Add("123239829", 2142);
	d.Add("123211240", 2203);
	d.Add("000000001", 9999);

	cout << "Size: " << d.Size() << endl << d["123239829"] << endl;

	d.Remove("123239829");

	cout << "Size: " << d.Size() << endl;
}
#pragma endregion