#include "Header.h"

// Overview and implementation of the dynamic stack data structure.
int main()
{
	// Class demo.
	Stack<int> data1;
	Stack<int> data2;

	data1.push(1);
	data1.push(2);
	data1.push(3);
	data2.push(4);
	data2.push(5);
	data2.push(6);
	data2.push(7);
	data1.pop();
	data2.pop();
	
	cout << data1.peek() << endl;
	
	data2.swap(data1);
	
	cout << data1.size() << endl << data2[1];

	return 0;
}