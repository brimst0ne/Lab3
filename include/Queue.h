#pragma once
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
	void PushElem(const ValType& elem);
	const ValType& PopElem();

	friend ostream& operator<< (ostream& ostr, const TQueue<ValType>& A) {
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
	Array = new const ValType * [_size];
	size = _size;
	first = 0;
	last = 0;
	DataCount = 0;
}

template<class ValType>
inline TQueue<ValType>::TQueue(TQueue& aq)
{
	Array = new const ValType * [aq.size];
	size = aq.size;
	first = aq.first;
	last = aq.last;
	DataCount = aq.DataCount;
}

template<class ValType>
inline TQueue<ValType>::~TQueue()
{
	delete[] Array;
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
inline void TQueue<ValType>::PushElem(const ValType& elem)
{
	if ((*this).IsFull()) throw logic_error("Queue is already full");
	if (Array == 0) throw logic_error("There is no queue");
	Array[first] = &elem;
	first = (first + 1) % size;
	DataCount++;
}

template<class ValType>
inline const ValType& TQueue<ValType>::PopElem()
{
	if (this->IsEmpty()) throw logic_error("Queue is empty");
	if (Array == 0) throw logic_error("There is no queue");
	const ValType* tmp = this->Array[this->first];
	this->Array[this->first] = 0;
	this->first = (this->first + 1) % this->size;
	this->DataCount--;
	return (*tmp);
}
