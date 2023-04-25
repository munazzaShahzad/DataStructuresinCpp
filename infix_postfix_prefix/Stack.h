#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
    T* data;
    int capacity;
    int top;
    void reSize(int);
public:
    Stack();
    Stack(const Stack<T>&);
    Stack& operator = (const Stack<T>&);
    ~Stack();
    void push(T);
    T pop();
    T stackTop() const;
    bool isFull() const;
    bool isEmpty() const;
    int getCapacity() const;
    int getNumberOfElements() const;
};