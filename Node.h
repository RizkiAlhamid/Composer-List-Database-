#ifndef Node_h
#define Node_h

#include <stdio.h>

template <class T>
class Node{
public:
    T data;
    Node<T>* next;
    Node();
    Node(T d);
};

//===========================
//  Default Constructor
//===========================
template<class T>
Node<T>::Node(){}

//===========================
//  Copy Constructor
//===========================
template<class T>
Node<T>::Node(T d) : data(d), next(nullptr) {}

#endif /* Node_h */
