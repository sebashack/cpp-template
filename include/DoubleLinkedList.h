#pragma once

#include <cstddef>
#include <iostream>

template<typename T>
class DNode
{
public:
    DNode(T& v) : value(v) {}

    T& value;
    DNode<T>* next = nullptr;
    DNode<T>* previous = nullptr;
};

template<typename T>
class DoubleLinkedList
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void pushBack(T& elem);
    void push(T& elem);
    T& getAt(size_t i);
    T* pop();
    T* popLast();
    size_t length();
    bool isEmpty();

    struct Iterator
    {
        using pointer           = T*;
        using reference         = T&;

        Iterator(DNode<T>* ptr) : m_ptr(ptr) {}

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
        DNode<T>* m_ptr;
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
    DNode<T>* head;
    DNode<T>* tail;
    size_t len = 0;
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    if (this->head != nullptr)
    {
        DNode<T>* nextNode = this->head->next;
        DNode<T>* tmp;
        delete this->head;

        while (nextNode != nullptr)
        {
            tmp = nextNode->next;
            delete nextNode;
            nextNode = tmp;
        }

        std::cout << "DoubleLinkedList object destroyed" << std::endl;
    }
}

template<typename T>
void DoubleLinkedList<T>::pushBack(T& elem)
{
    DNode<T>* newNode = new DNode(elem);

    if (this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->previous = this->tail;
        this->tail->next = newNode;
        this->tail = this->tail->next;
    }

    this->len++;
}

template<typename T>
void DoubleLinkedList<T>::push(T& elem)
{
    DNode<T>* newNode = new DNode(elem);

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

    this->len++;
}

template<typename T>
T* DoubleLinkedList<T>::popLast()
{
    if (this->tail == nullptr)
    {
        return nullptr;
    }
    else
    {
        T* value = &(this->tail->value);

        if (this->head == this->tail)
        {
            this->head = nullptr;
            this->tail = nullptr;

        }
        else
        {
            this->tail = this->tail->previous;
            this->tail->next = nullptr;
        }

        this->len--;

        return value;
    }
}

template<typename T>
T& DoubleLinkedList<T>::getAt(size_t i)
{
    if (i < 0 || i >= this->length())
    {
        throw "Index out of range";
    }

    Iterator it = this->begin();

    for (size_t j = 0; j < i ; ++j)
    {
        ++it;
    }

    return *(it);
}

template<typename T>
T* DoubleLinkedList<T>::pop()
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
            this->head->previous = nullptr;
        }

        this->len--;

        return value;
    }
}

template<typename T>
size_t DoubleLinkedList<T>::length()
{
    return this->len;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty()
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
