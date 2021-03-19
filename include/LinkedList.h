#pragma once

#include <cstddef>
#include <iostream>

template<typename T>
class Node
{
public:
    Node(T elem);
    ~Node();

    T value;
    Node<T>* next;
};


template<typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void insert(T elem);
    T pop();
    bool isEmpty();

private:
    Node<T>* head;
    Node<T>* tail;
};

template<typename T>
Node<T>::Node(T elem)
{
    this->value = elem;
    this->next = NULL;
}

template<typename T>
Node<T>::~Node()
{
    std::cout << "Node object destroyed" << std::endl;
}

template<typename T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    std::cout << "LinkedList object destroyed" << std::endl;
}

template<typename T>
void LinkedList<T>::insert(T elem)
{
    Node<T>* newNode = new Node(elem);

    if (this->head == NULL)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->next = newNode;
        this->tail = this->tail->next;
    }
}

template<typename T>
T LinkedList<T>::pop()
{
    T value = this->head->value;
    this->head = this->tail;
    this->tail = this->tail->next;

    return value;
}


template<typename T>
bool LinkedList<T>::isEmpty()
{
    if (this->head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
