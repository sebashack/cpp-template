#pragma once

#include <cstddef>
#include <iostream>

template<typename T>
class Node
{
public:
    Node(T& v) : value(v) {}

    T& value;
    Node<T>* next;
};

template<typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void pushBack(T& elem);
    void push(T& elem);
    T* pop();
    bool isEmpty();

    struct Iterator
    {
        using pointer           = T*;
        using reference         = T&;

        Iterator(Node<T>* ptr) : m_ptr(ptr) {}

        reference operator*()
        {
            return this->m_ptr->value;
        }
        pointer operator->()
        {
            return &(this->m_ptr->value);
        }
        Iterator& operator++()
        {
            this->m_ptr = this->m_ptr->next;

            return *this;
        }
        Iterator operator++(int)
        {
            Iterator it = *this;
            ++this;
            return it;
        }
        bool operator== (const Iterator& it)
        {
            return this->m_ptr == it.m_ptr;
        };
        bool operator!=(const Iterator& it)
        {
            return this->m_ptr != it.m_ptr;
        }

    private:
        Node<T>* m_ptr;
    };

    Iterator begin()
    {
        return Iterator(this->head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

private:
    Node<T>* head;
    Node<T>* tail;
};

template<typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    if (this->head != nullptr)
    {
        Node<T>* nextNode = this->head->next;
        Node<T>* tmp;
        delete this->head;

        while (nextNode != nullptr)
        {
            tmp = nextNode->next;
            delete nextNode;
            nextNode = tmp;
        }

        std::cout << "LinkedList object destroyed" << std::endl;
    }
}

template<typename T>
void LinkedList<T>::pushBack(T& elem)
{
    Node<T>* newNode = new Node(elem);

    if (this->head == nullptr)
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
void LinkedList<T>::push(T& elem)
{
    Node<T>* newNode = new Node(elem);

    if (this->head == nullptr)
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
    if (this->head == nullptr)
    {
        return nullptr;
    }
    else
    {
        T* value = &(this->head->value);

        if (this->head->next == nullptr)
        {
            this->head = nullptr;
            this->tail = nullptr;
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
    if (this->head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
