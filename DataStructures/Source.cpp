#include "Header.h"

void StackPresentation();
void QueuePresentation();

int main()
{
	StackPresentation();
	QueuePresentation();

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