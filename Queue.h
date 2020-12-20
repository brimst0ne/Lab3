#pragma once
#include <vector>
#include "Stack.h"

template <class ValType>
class TQueue {
public:
	TQueue();
	TQueue(int _size);
	TQueue(TQueue& aq);
	~TQueue();
	int GetSize();
	bool IsEmpty();
	bool IsFull();
	void PushElem(ValType elem);
	ValType PopElem();

	ValType FindKMAX(ValType k);

	friend ostream& operator<< (ostream& ostr, const TQueue<ValType>& A) {
		for (int i = 0; i < A.size; i++) {
			ostr << A.Array[i] << " ";
		}
		return ostr;
	}
protected:
	ValType* Array;
	int size;
	int first;
	int last;
	int DataCount;
};

template<class ValType>
inline TQueue<ValType>::TQueue()
{
	Array = 0;
	size = 0;
	first = 0;
	last = -1;
	DataCount = 0;
}

template<class ValType>
inline TQueue<ValType>::TQueue(int _size)
{
	if (_size < 0) throw logic_error("Incorrect size");
	Array = new ValType[_size];
	size = _size;
	first = 0;
	last = 0;
	DataCount = 0;
}

template<class ValType>
inline TQueue<ValType>::TQueue(TQueue& aq)
{
	Array = new ValType[aq.size];
	size = aq.size;
	first = aq.first;
	last = aq.last;
	DataCount = aq.DataCount;
}

template<class ValType>
inline TQueue<ValType>::~TQueue()
{
	delete[] Array;
	Array = 0;
}

template<class ValType>
inline int TQueue<ValType>::GetSize()
{
	return size;
}

template<class ValType>
inline bool TQueue<ValType>::IsEmpty()
{
	return (DataCount == 0);
}

template<class ValType>
inline bool TQueue<ValType>::IsFull()
{
	return (DataCount == size);
}

template<class ValType>
inline void TQueue<ValType>::PushElem(ValType elem)
{
	if ((*this).IsFull()) throw logic_error("Queue is already full");
	if (Array == 0) throw logic_error("There is no queue");
	Array[first] = elem;
	first = (first + 1) % size;
	DataCount++;
}

template<class ValType>
inline ValType TQueue<ValType>::PopElem()
{
	if (this->IsEmpty()) throw logic_error("Queue is empty");
	if (Array == 0) throw logic_error("There is no queue");
	ValType tmp = this->Array[this->first];
	this->Array[this->first] = 0;
	this->first = (this->first + 1) % this->size;
	this->DataCount--;
	return tmp;
}

template<class ValType>
inline ValType TQueue<ValType>::FindKMAX(ValType k)
{
	if (Array == 0) throw logic_error("No queue");
	if (k == 0) throw logic_error("There's no such elements");
	ValType kmax = 0;
	vector<ValType> vec;
	vector<ValType> vec1;
	for (int i = (*this).DataCount - 1; i >= 0; i--) {
		vec.push_back((*this).PopElem());
	}
	
	for (int i = 0; i < vec.size(); i++) {
		if ((vec.at(i) % k) == 0)
			vec1.push_back(vec.at(i));
	}
	kmax = vec1.at(0);
	for (int i = 0; i < vec1.size(); i++) {
		if (vec1.at(i) > kmax)
			kmax = vec1.at(i);
	}
	for (int i = 0; i < vec.size(); i++) {
		(*this).PushElem(vec.at(i));
	}
	return kmax;
}
