#pragma once
#include <math.h>
#include "Stack.h"
#include <iostream>


using namespace std;

template <class ValType>
class TMultiStack {
public:
	TMultiStack(int size = 1, int _stackCount = 1);
	TMultiStack(TMultiStack<ValType>& _v);
	~TMultiStack();

	TMultiStack<ValType>& operator =(TMultiStack<ValType>& _v);

	void Push(ValType d, int i);
	ValType Get(int i);

	bool IsEmpty(int i) const;
	bool IsFull(int i) const;

	template <class T>
	friend ostream& operator<< (ostream& ostr, const TMultiStack<T>& A);

	template <class T>
	friend istream& operator>> (istream& istr, TMultiStack<T>& A);

	int GetSize();

protected:
	int length;
	ValType* Data;
	int stackCount;
	TStack<ValType>* stacks;
	void StackRelocation(int index);
	ValType** oldData;
};

template<class ValType>
inline TMultiStack<ValType>::TMultiStack(int size, int _stackCount)
{
	if ((size > 0) && (_stackCount > 0)) {
		this->length = size;
		this->stackCount = _stackCount;
		Data = new ValType[length];
		for (int i = 0; i < length; i++) {
			Data[i] = 0;
		}
		int count = int(floor(double(size) / stackCount));
		int* sizes = new int[this->stackCount];

		for (int i = 0; i < (stackCount - 1); i++) {
			sizes[i] = count;
		}
		sizes[stackCount - 1] = size - (count * (stackCount - 1));
		oldData = new ValType * [stackCount];
		this->stacks = new TStack<ValType>[stackCount];

		int k = 0;
		for (int i = 0; i < stackCount; i++) {
			this->stacks[i].SetData(&(Data[k]), sizes[i], 0);
			this->oldData[i] = &(Data[k]);
			k = k + sizes[i];
		}
	}
	else
		throw - 1;
}

template<class ValType>
inline TMultiStack<ValType>::TMultiStack(TMultiStack<ValType>& _v)
{
	length = _v.length;
	stackCount = _v.stackCount;
	Data = new ValType[length];
	for (int i = 0; i < length; i++) {
		Data[i] = _v.Data[i];
	}
	stacks = new TStack<ValType>[stackCount];
	for (int i = 0; i < stackCount; i++) {
		stacks[i] = _v.stacks[i];
	}
	oldData = _v.oldData;
}

template<class ValType>
inline TMultiStack<ValType>::~TMultiStack()
{
	length = 0;
	stackCount = 0;
	if (Data != 0) {
		delete[] Data;
		Data = 0;
	}
}

template<class ValType>
inline TMultiStack<ValType>& TMultiStack<ValType>::operator=(TMultiStack<ValType>& _v)
{
	if (this == &_v)
		return *this;
	length = _v.length;
	delete[] Data;
	delete[] stacks;
	Data = new ValType[length];
	for (int i = 0; i < length; i++)
		Data[i] = _v.Data[i];
	stacks = new TStack<ValType>[stackCount];
	for (int i = 0; i < stackCount; i++) {
		stacks[i] = _v.stacks[i];
	}

	return *this;
}

template<class ValType>
inline void TMultiStack<ValType>::Push(ValType d, int i)
{
	if ((i < 0) || (i >= stackCount)) {
		throw - 1;
	}
	if (stacks[i].IsFull()) {
		//throw - 2;
		StackRelocation(i);
	}
	stacks[i].PushElem(d);
}

template<class ValType>
inline ValType TMultiStack<ValType>::Get(int i)
{
	if ((i < 0) || (i >= stackCount)) {
		throw - 1;
	}
	if (stacks[i].IsEmpty()) {
		throw - 2;
	}
	ValType d = stacks[i].PopElem();
	return d;
}

template<class ValType>
inline bool TMultiStack<ValType>::IsEmpty(int i) const
{
	if ((i < 0) || (i >= stackCount)) {
		throw - 1;
	}
	return stacks[i].IsEmpty();
}

template<class ValType>
inline bool TMultiStack<ValType>::IsFull(int i) const
{
	if ((i < 0) || (i >= stackCount)) {
		throw - 1;
	}
	return stacks[i].IsFull();
}

template<class ValType>
inline int TMultiStack<ValType>::GetSize()
{
	return length;
}

template<class ValType>
inline void TMultiStack<ValType>::StackRelocation(int index)
{
	int freeSize = 0;
	for (int i = 0; i < stackCount; i++) {
		freeSize += stacks[i].GetSize() - stacks[i].GetCount();
	}
	if (freeSize == 0)
		throw - 2;
	int count = int(floor(double(freeSize) / stackCount));
	int* sizes = new int[this->stackCount];

	for (int i = 0; i < (stackCount - 1); i++) {
		sizes[i] = stacks[i].GetCount() + count;
	}
	int c = stacks[stackCount - 1].GetCount();
	sizes[this->stackCount - 1] = c + (freeSize - (count * (this->stackCount - 1)));
	
	ValType** newData = new ValType * [stackCount];
	
	int k = 0;
	for (int i = 0; i < stackCount; i++) {
		newData[i] = &(Data[k]);
		k = k + sizes[i];
	}

	for (int i = 0; i < stackCount; i++) {
		if (newData[i] == oldData[i]) {
			stacks[i].SetData(newData[i], sizes[i], stacks[i].GetCount());
		}
		else if (newData[i] < oldData[i]) {
			for (int j = 0; j < stacks[i].GetCount(); j++) {
				newData[i][j] = oldData[i][j];
			}
			stacks[i].SetData(newData[i], sizes[i], stacks[i].GetCount());
		}
		else if (newData[i] > oldData[i]) {
			int k = i;
			for (; k < stackCount; k++) {
				if (newData[k] > oldData[k])
					continue;
				else
					break;
			}
			k--;

			for (int s = k; s >= i; s--) {
				for (int j = stacks[s].GetCount() - 1; j >= 0 ; j--) {
					newData[s][j] = oldData[s][j];
				}
				stacks[s].SetData(newData[s], sizes[s], stacks[s].GetCount());
			}
		}
	}
	ValType** buf = oldData;
	oldData = newData;
	delete[] buf;
	delete[] sizes;
}

template<class T>
inline ostream& operator<<(ostream& ostr, const TMultiStack<T>& A)
{
	for (int i = 0; i < A.stackCount; i++) {
		ostr << "[" << A.stacks[i] << "]" <<endl;
	}
	return ostr;
}

template<class T>
inline istream& operator>>(istream& istr, TMultiStack<T>& A)
{
	int stCount = 0;
	istr >> stCount;
	int size = 0;
	istr >> size;
	A.Resize(size, stCount);
	for (int i = 0; i < stCount; i++) {
		istr >> A.stacks[i];
	}
	return istr;
}
