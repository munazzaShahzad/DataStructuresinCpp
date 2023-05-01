#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class StackLSLL
{
    Node<T>* head;
    int noe = 0;
public:
    StackLSLL();
    ~StackLSLL();
    void push(T);           //insertAtHead
    T pop();                //removeAtHead
    T stackTop() const;
    bool isEmpty() const;
    int getNumberOfElements() const;
    void display() const;
};