#pragma once

#include <cstddef>
#include <iostream>

template<typename T>
class Node
{
public:
    Node(T elem);

    T value;
    Node<T>* next;

    void print();
};

template<typename T>
Node<T>::Node(T elem)
{
    this->value = elem;
    this->next = NULL;
}

template<typename T>
void Node<T>::print()
{
    Node* nextNode = this->next;

    std::cout << this->value << std::endl;

    while (nextNode != NULL)
    {
        std::cout << nextNode->value << std::endl;
        nextNode = nextNode->next;
    }
}

template<typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void insert(T elem);
    void push(T elem);
    T* pop();
    bool isEmpty();
    void print();

private:
    Node<T>* head;
    Node<T>* tail;
};


template<typename T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    if (this->head != NULL)
    {
        Node<T>* nextNode = this->head->next;
        Node<T>* tmp;
        delete this->head;

        while (nextNode != NULL)
        {
            tmp = nextNode->next;
            delete nextNode;
            nextNode = tmp;
        }

        std::cout << "LinkedList object destroyed" << std::endl;
    }
}


template<typename T>
void LinkedList<T>::print()
{

    if (this->isEmpty())
    {
        std::cout << "empty" << std::endl;
    }
    else
    {
        this->head->print();
    }
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
void LinkedList<T>::push(T elem)
{
    Node<T>* newNode = new Node(elem);

    if (this->head == NULL)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->next = this->head;
        this->head = newNode;
    }
}

template<typename T>
T* LinkedList<T>::pop()
{
    if (this->head == NULL)
    {
        return NULL;
    }
    else
    {
        T* value = &(this->head->value);

        if (this->head->next == NULL)
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            this->head = this->head->next;
        }

        return value;
    }
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
