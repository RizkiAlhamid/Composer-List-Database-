#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList{
private:
    Node<T>* first;
    Node<T>* last;
public:
    LinkedList();
    ~LinkedList();
    void printList() const;
    void append(const T data);
    void prepend(const T data);
    bool removeFront();
    void insert(const T data);
    bool remove(const T data);
    bool find(const T data);
    bool isEmpty() const;
    T getFirst() const;
    T getLast() const;
};

//===========================
//  Default Constructor
//===========================
template<class T>
LinkedList<T>::LinkedList(){
    first = nullptr;
    last = nullptr;
}

//===========================
//  Destructor
//===========================
template<class T>
LinkedList<T>::~LinkedList(){
    Node<T> * iter = first;
    Node<T> * temp = nullptr;
    
    while(iter != nullptr){
        temp = iter->next;
        delete iter;
        iter = temp;
    }
}

//===========================
//  Print List Method
// Showing all the data in the linked list
//===========================
template<class T>
void LinkedList<T>::printList() const{
    if(first == nullptr)
        return;
    else{
        Node<T>* iter = first;
        while(iter != nullptr){
            cout << iter->data;
            iter = iter->next;
        }
        cout << endl;
    }
}

//===========================
//  Append method
// Receive a data as argument and append it to the last node in the list
//===========================
template<class T>
void LinkedList<T>::append(const T data){
       Node<T>* temp = new Node<T>;
       temp->data = data;
       temp->next = nullptr;
       if(first == nullptr){
           first = temp;
           last = temp;
       }
       else{
           Node<T>* iter = first;
           while(iter->next != nullptr){
               iter = iter->next;
           }
           iter->next = temp;
           last = temp;
       }
   }

//===========================
//  Prepend Method
// Receives data and append it at the beginning od the list
//===========================
template<class T>
void LinkedList<T>::prepend(const T data){
    Node<T>* temp = new Node<T>;
    temp->data = data;
    if(first == nullptr){
        first = temp;
        last = temp;
    } else{
        temp->next = first;
        first = temp;
    }
}

//===========================
//  Remove Front method
// remove the first node of the list
//===========================
template<class T>
bool LinkedList<T>::removeFront(){
       if(first == nullptr)
           return false;
       else{
           Node<T>* target = first;
           first = first->next;
           delete target;
       }
       return true;
   }

//===========================
//  Insert method
// Receives a data and insert the data to the list
// with the in increasing order
//===========================
template<class T>
void LinkedList<T>::insert(const T data){
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->next = nullptr;
    if(first == nullptr){
        first = temp;
        last = temp;
    } else{
        Node<T>* current = first;
        Node<T>* preNode = nullptr;
        
        while(current != nullptr && current->data < data){
            preNode = current;
            current = current->next;
        }
        if(preNode == nullptr){
            temp->next = first;
            first = temp;
            last = temp->next;
        } else{
            temp->next = current;
            preNode->next = temp;
            last = temp;
        }
    }
}

//===========================
//  Remove method
// receives a data and search the data through the list
// and remove it if it's found
//===========================
template<class T>
bool LinkedList<T>::remove(const T data){
    Node<T>* current = first;
    Node<T>* preNode = nullptr;
    
    if(current == nullptr)
        return false;
    else if(current->data == data){
        current = first->next;
        delete first;
        first = current;
    } else{
        while(current != nullptr && current->data != data){
            preNode = current;
            current = current->next;
        }
        if(current == nullptr){
            return false;
        } else{
            preNode->next = current->next;
            delete current;
        }
    }
    return true;
}

//===========================
//  Find method
// receives a data and search for that data in the list
// returns true if it's found, return false otherwise
//===========================
template<class T>
bool LinkedList<T>::find(const T data){
    Node<T>* find = first;
    while(find != nullptr){
        if(find->data == data){
            return true;
        }else{
            find = find->next;
        }
    }
    return false;
}

//===========================
//  Is Empty method
// check if the list is empty or not
// return true if empty, false otherwise
//===========================
template<class T>
bool LinkedList<T>::isEmpty() const{
    if(first == nullptr)
        return true;
    return false;
}

//===========================
//  Get First method
// get and return the first node's data of the list
//===========================
template<class T>
T LinkedList<T>::getFirst() const{
    return first->data;
}

//===========================
//  Get Last method
// get and return the last node's data of the list
//===========================
template<class T>
T LinkedList<T>::getLast() const{
    return last->data;
}

#endif /* LinkedList_h */
