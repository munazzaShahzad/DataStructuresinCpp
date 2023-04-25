#include "NDarrayIL.h"

template <typename T>
NDarrayIL<T>::NDarrayIL(initializer_list<T> l)
{
	N = l.size();
	if (N != 0)
	{
		int x;
		dim = new int[N];
		noe = 1;
		int i = 0;
		for (auto x: l)
		{
			noe *= x;
			dim[i] = x;
			i++;
		}
		data = new T[noe];
	}
	else
	{
		dim = nullptr;
		data = nullptr;
		noe = 0;
	}
}

template <typename T>
NDarrayIL<T>::NDarrayIL(const NDarrayIL<T>& ref) :NDarrayIL()
{
	if (ref.N == 0)
		return;
	N = ref.N;
	dim = new int[N];
	for (int i = 0; i < N; i++)
		dim[i] = ref.dim[i];
	noe = ref.noe;
	for (int i = 0; i < noe; i++)
		data[i] = ref.data[i];
}

template <typename T>
NDarrayIL<T>& NDarrayIL<T>::operator= (const NDarrayIL<T>& ref)
{
	if (this == &ref)
		return *this;
	this->~NDarrayIL();
	if (ref.N == 0)
		return *this;
	N = ref.N;
	dim = new int[N];
	noe = ref.noe;
	for (int i = 0; i < noe; i++)
		data[i] = ref.data[i];
	return *this;
}

template <typename T>
T& NDarrayIL<T>::valueAt(initializer_list<T> l)
{
	int ind = 0, i = 0;
	for (auto x: l)
	{
		int mul = x;
		for (int j = i + 1; j < N; j++)
			mul *= dim[j];
		ind += mul;
		i++;
	}
	return data[ind];
}

template <typename T>
const int* NDarrayIL<T>::getDimensions() const
{
	return dim;
}

template <typename T>
void NDarrayIL<T>::reSize(initializer_list<T> l)		//not changing no of dimensions
{
	if (l.size() != N)
		return;
	int noeTemp = 1;
	int noDim = N;
	int* dimTemp = new int[N];
	int i = 0;
	for (auto x: l)
	{
		noeTemp *= x;
		dimTemp[i] = x;
		i++;
	}
	T* temp = new T[noeTemp];
	int s = noe < noeTemp ? noe : noeTemp;
	for (int i = 0; i < s; i++)
		temp[i] = data[i];
	this->~NDArray();
	data = temp;
	N = noDim;
	dim = dimTemp;
	noe = noeTemp;
}

template <typename T>
NDarrayIL<T>::~NDarrayIL()
{
	if (data)
	{
		delete[] data;
		delete[] dim;
		noe = 0;
		N = 0;
	}
}