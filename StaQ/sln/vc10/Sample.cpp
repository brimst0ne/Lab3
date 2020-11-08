#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Программа тестирования поддержки стеков и очередей" << endl;
	//TStack<int> A(5);
	TQueue<int> A(5);
	int arr[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
		cout << arr[i] << endl;
		A.PushElem(arr[i]);
	}
	cout << A << endl;
	A.PopElem();
	cout << A << endl;
	//A.PushElem(5);
	//cout << A << endl;
	/*for (int i = A.GetFirstElem(); i < A.GetSize(); i++) {
		cout << A.PopElem() << " " << endl;
	}*/
	
}