#pragma once
#include <iostream>

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
	bool IsEmpty();
	bool IsFull();
	const ValType** GetMemory();
	void PushElem(const ValType& as);
	const ValType& PopElem();
	
	friend ostream& operator<< (ostream& ostr, const TStack<ValType>& A) {
		for (int i = 0; i < A.size; i++) {
			ostr << A.Array[i] << " ";
		}
		return ostr;
	}
protected:
	const ValType** Array;
	int size;
	int first;
	int last;
	int DataCount;
};

template<class ValType>
inline TStack<ValType>::TStack()
{
	Array = 0;
	size = 0;
	first = 0;
	DataCount = 0;
}

template<class ValType>
inline TStack<ValType>::TStack(int _size)
{
	if (_size < 0) throw logic_error("Wrong size");
	Array = new const ValType * [_size];
	size = _size;
	first = 0;
	DataCount = 0;
}

template<class ValType>
inline TStack<ValType>::TStack(TStack& as)
{
	Array = new const ValType * [as.size];
	size = as.size;
	DataCount = as.DataCount;
	first = as.first;
}

template<class ValType>
inline TStack<ValType>::~TStack()
{
	delete[] Array;
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
inline const ValType** TStack<ValType>::GetMemory()
{
	return Array;
}

template<class ValType>
inline void TStack<ValType>::PushElem(const ValType& as)
{
	if ((*this).IsFull()) throw logic_error("Stack overflow");
	if (Array == 0) throw logic_error("No stack");
	Array[first] = &as;
	first++;
	DataCount++;
}

template<class ValType>
inline const ValType& TStack<ValType>::PopElem()
{
	if (this->IsEmpty()) throw logic_error("Stack is empty");
	if (Array == 0) throw logic_error("There is no stack");
	const ValType* tmp = Array[first];
	Array[first - 1] = 0;
	first--;
	DataCount--;
	return (*tmp);
}