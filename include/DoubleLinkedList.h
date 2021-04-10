#pragma once

#include <cstddef>
#include <iostream>
#include <time.h>

template<typename T>
class DNode
{
public:
    DNode(T v) : value(v) {}

    T value;
    DNode<T>* next = nullptr;
    DNode<T>* previous = nullptr;

    void update(T& v);
};

template<typename T>
void DNode<T>::update(T& v)
{
    this->value = v;
}

template<typename T>
class DoubleLinkedList
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void pushBack(T elem);
    void push(T elem);
    DNode<T>* getMutAt(size_t i);
    T& getAt(size_t i) const;
    void insertAt(T elem, size_t i);
    void insertSorted(T elem);
    void swapValues(size_t i, size_t j);
    void shuffle();
    T* removeAt(size_t i);
    T* pop();
    T* popLast();
    size_t length() const;
    bool isEmpty() const;

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
void DoubleLinkedList<T>::pushBack(T elem)
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
void DoubleLinkedList<T>::push(T elem)
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
        this->head->previous = newNode;
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
T* DoubleLinkedList<T>::removeAt(size_t i)
{
    if (i < 0 || i >= this->length())
    {
        throw "Index out of range";
    }

    if (i == 0)
    {
        return this->pop();
    }

    if (i == this->length() - 1)
    {
        return this->popLast();
    }

    DNode<T>* node = this->head;

    for (size_t j = 0; j < i ; ++j)
    {
        node = node->next;
    }

    node->previous->next = node->next;
    node->next->previous = node->previous;
    node->previous = nullptr;
    node->next = nullptr;

    this->len--;

    return &(node->value);
}

template<typename T>
void DoubleLinkedList<T>::insertAt(T elem, size_t i)
{
    if (i < 0 || i > this->length())
    {
        throw "Index out of range";
    }

    if (i == 0)
    {
        this->push(elem);
        return;
    }

    if (i == this->length())
    {
        this->pushBack(elem);
        return;
    }

    DNode<T>* node = this->head;

    for (size_t j = 0; j < i ; ++j)
    {
        node = node->next;
    }

    DNode<T>* newNode = new DNode(elem);
    newNode->next = node;
    newNode->previous = node->previous;
    node->previous->next = newNode;
    node->previous = newNode;

    this->len++;
}

template<typename T>
void DoubleLinkedList<T>::insertSorted(T elem)
{
    if (this->len < 1 || elem < this->head->value)
    {
        this->push(elem);
        return;
    }

    DNode<T>* newNode = new DNode(elem);
    DNode<T>* node = this->head->next;

    while (node != nullptr)
    {
        if (elem < node->value)
        {

            newNode->next = node;
            newNode->previous = node->previous;
            node->previous->next = newNode;
            node->previous = newNode;

            this->len++;

            return;
        }

        node = node->next;
    }

    this->pushBack(elem);
}

template<typename T>
void DoubleLinkedList<T>::swapValues(size_t i, size_t j)
{
    if (i < 0 || j < 0|| i >= this->length() || j >= this->length())
    {
        throw "Index out of range";
    }

    DNode<T>* nodei = this->getMutAt(i);
    DNode<T>* nodej = this->getMutAt(j);

    T valAtI = nodei->value;
    T valAtJ = nodej->value;

    nodei->update(valAtJ);
    nodej->update(valAtI);
}

template<typename T>
void DoubleLinkedList<T>::shuffle()
{
    std::srand(time(0));

    size_t min = 0;
    size_t max = this->length() - 1;
    size_t l;
    size_t u;

    for (size_t i = 0; i < this->length(); ++i)
    {
        l = min + std::rand() % (max - min + 1);
        u = min + std::rand() % (max - min + 1);

        this->swapValues(l, u);
    }
}

template<typename T>
DNode<T>* DoubleLinkedList<T>::getMutAt(size_t i)
{
    if (i < 0 || i >= this->length())
    {
        throw "Index out of range";
    }

    DNode<T>* node = this->head;

    for (size_t j = 0; j < i ; ++j)
    {
        node = node->next;
    }

    return node;
}

template<typename T>
T& DoubleLinkedList<T>::getAt(size_t i) const
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
size_t DoubleLinkedList<T>::length() const
{
    return this->len;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const
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
