#pragma once

#include <iostream>


template<typename K, typename V>
class BNode
{
public:
    BNode(K& k, V& v) : key(k), value(v) {}

    K& key;
    V& value;
    BNode<K, V>* left = nullptr;
    BNode<K, V>* right = nullptr;
};

template<typename K, typename V>
class ASTree
{
public:
    ASTree();
    ~ASTree();

    void insertNode(K& k);
    void insertLeaf(K& k, V& v);
    bool isEmpty() const;

private:
    BNode<K, V>* root;
    size_t len = 0;
};

template<typename K, typename V>
ASTree<K, V>::ASTree()
{
    this->root = nullptr;
}

template<typename K, typename V>
void ASTree<K, V>::insertNode(K& k)
{
    BNode<K, V>* newNode = BNode(k, nullptr);

    if (this->isEmpty())
    {
        this->root = newNode;
    }
    else
    {
        // TODO
    }
}

template<typename K, typename V>
void ASTree<K, V>::insertLeaf(K& k, V& v)
{
    BNode<K, V>* newNode = BNode(k, v);

    if (this->isEmpty())
    {
        this->root = newNode;
    }
    else
    {
        // TODO
    }
}

template<typename K, typename V>
bool ASTree<K, V>::isEmpty() const
{
    if (this->root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
