#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <class ValType>
class TStack {
public:
	TStack();
	TStack(int _size);
	TStack(TStack& as);
	~TStack();
	int GetSize();
	int GetFirstElem();
	int GetCount();
	bool IsEmpty();
	bool IsFull();
	ValType* GetMemory();
	void PushElem(ValType as);
	ValType PopElem();

	void SortPushElem(ValType elem);
	bool ElemBelongs(ValType elem);
	
	void SetData(ValType* _x, int _size, int _first);
	friend ostream& operator<< (ostream& ostr, const TStack<ValType>& A) {
		for (int i = 0; i < A.size; i++) {
			ostr << A.Array[i] << " ";
		}
		return ostr;
	}
protected:
	ValType* Array;
	int size;
	int first;
	int DataCount;
};

template<class ValType>
inline TStack<ValType>::TStack()
{
	Array = new ValType[1];
	Array[0] = 0;
	size = 1;
	first = 0;
	DataCount = 0;
}

template<class ValType>
inline TStack<ValType>::TStack(int _size)
{
	if (_size < 0) throw logic_error("Wrong size");
	Array = new ValType[_size];
	size = _size;
	first = 0;
	DataCount = 0;
	for (int i = 0; i < _size; i++) {
		Array[i] = 0;
	}
}

template<class ValType>
inline TStack<ValType>::TStack(TStack& as)
{
	Array = new ValType [as.size];
	size = as.size;
	DataCount = as.DataCount;
	first = as.first;
}

template<class ValType>
inline TStack<ValType>::~TStack()
{
	delete[] Array;
	Array = 0;
	size = 0;
	first = 0;
}

template<class ValType>
inline int TStack<ValType>::GetSize()
{
	return size;
}

template<class ValType>
inline int TStack<ValType>::GetFirstElem()
{
	return first;
}

template<class ValType>
inline int TStack<ValType>::GetCount()
{
	return first;
}

template<class ValType>
inline bool TStack<ValType>::IsEmpty()
{
	return (DataCount == 0);
}

template<class ValType>
inline bool TStack<ValType>::IsFull()
{
	return (DataCount == size);
}

template<class ValType>
inline ValType* TStack<ValType>::GetMemory()
{
	return Array;
}

template<class ValType>
inline void TStack<ValType>::PushElem(ValType as)
{
	if ((*this).IsFull()) throw logic_error("Stack overflow");
	if (Array == 0) throw logic_error("No stack");
	Array[first] = as;
	first++;
	DataCount++;
}

template<class ValType>
inline ValType TStack<ValType>::PopElem()
{
	if (first == 0) throw logic_error("Stack is empty");
	if (Array == 0) throw logic_error("There is no stack");
	ValType tmp = Array[first - 1];
	Array[first - 1] = 0;
	first--;
	DataCount--;
	return (tmp);
}

template<class ValType>
inline void TStack<ValType>::SortPushElem(ValType elem)
{
	if ((*this).IsFull()) throw logic_error("Stack overflow");
	if (Array == 0) throw logic_error("No stack");
	vector<ValType> vec;
	for (int i = (*this).DataCount - 1; i >= 0; i--) {
		vec.push_back((*this).PopElem());
	}
	vec.push_back(elem);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << endl;
	}
	cout << endl;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << endl;
	}
	cout << endl;
	for (int i = 0; i < vec.size(); i++) {
		(*this).PushElem(vec.at(i));
	}
}

template<class ValType>
inline bool TStack<ValType>::ElemBelongs(ValType elem)
{
	if ((*this).IsFull()) throw logic_error("Stack overflow");
	if (Array == 0) throw logic_error("No stack");
	/*for (int i = 0; i < first; i++) {
		if (Array[i] == elem) {
			cout << "The designated element belongs to this stack" << endl;
			return true;
		}	
	}
	cout << "The designated element does not belong to this stack" << endl;
	return false;*/
	vector<ValType> vec;
	for (int i = (*this).DataCount - 1; i >= 0; i--) {
		vec.push_back((*this).PopElem());
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << endl;
	}
	cout << endl;
	for (int i = 0; i < vec.size(); i++) {
		if (vec.at(i) == elem) {
			cout << "The designated element belongs to this stack" << endl;
			for (int j = (vec.size() - 1); j >= 0; j--) {
				(*this).PushElem(vec.at(j));
			}
			return true;
		}
	}
	for (int i = (vec.size() - 1); i >= 0; i--) {
		(*this).PushElem(vec.at(i));
	}
	cout << "The designated element does not belong to this stack" << endl;
	return false;
}

template<class ValType>
inline void TStack<ValType>::SetData(ValType* _x, int _size, int _first)
{
	(*this).Array = _x;
	(*this).size = _size;
	(*this).first = _first;
	(*this).DataCount = 0;
}
