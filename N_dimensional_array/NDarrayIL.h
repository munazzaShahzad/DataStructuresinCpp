#pragma once
#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class NDarrayIL
{
	T* data;
	int* dim;
	int N;		//Dimensions
	int noe;	//no of elements
public:
	NDarrayIL(initializer_list<T> l);
	NDarrayIL(const NDarrayIL<T>& ref);
	NDarrayIL<T>& operator= (const NDarrayIL<T>& ref);
	T& valueAt(initializer_list<T> l);
	const int* getDimensions() const;
	void reSize(initializer_list<T> l);
	~NDarrayIL();
};

