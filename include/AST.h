#pragma once

#include <assert.h>
#include <iostream>


template<typename K, typename V>
class ASTree
{
public:
    ASTree(K k);
    ASTree(V v);
    ASTree<K, V>* addLNonTerminal(K k);
    ASTree<K, V>* addRNonTerminal(K k);

    void addLTerminal(V v);
    void addRTerminal(V v);

    K key;
    V value;
    ASTree<K, V>* left = nullptr;
    ASTree<K, V>* right = nullptr;
};

template<typename K, typename V>
ASTree<K, V>::ASTree(K k)
{
    this->key = k;
}

template<typename K, typename V>
ASTree<K, V>::ASTree(V v)
{
    this->value = v;
}

template<typename K, typename V>
ASTree<K, V>* ASTree<K, V>::addLNonTerminal(K k)
{
    assert (this->left == nullptr);
    ASTree<K, V>* newNode = new ASTree(k);

    this->left = newNode;

    return newNode;
}

template<typename K, typename V>
void ASTree<K, V>::addLTerminal(V v)
{
    assert (this->left == nullptr);
    ASTree<K, V>* newNode = new ASTree(v);

    this->left = newNode;
}

template<typename K, typename V>
ASTree<K, V>* ASTree<K, V>::addRNonTerminal(K k)
{
    assert (this->right == nullptr);
    ASTree<K, V>* newNode = new ASTree(k);

    this->right = newNode;

    return newNode;
}

template<typename K, typename V>
void ASTree<K, V>::addRTerminal(V v)
{
    assert (this->right == nullptr);
    ASTree<K, V>* newNode = new ASTree(v);

    this->right = newNode;
}
