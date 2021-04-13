#pragma once

#include <assert.h>
#include <iostream>

enum operation { Sum, Subtract, Multiply, Divide };

template<typename V>
class ASTree
{
public:
    ~ASTree<V>();
    ASTree(operation op);
    ASTree(V v);
    ASTree<V>* addLNonTerminal(operation op);
    ASTree<V>* addRNonTerminal(operation op);

    void addLTerminal(V v);
    void addRTerminal(V v);
    V eval();

private:
    operation op;
    V value;
    bool is_terminal;
    ASTree<V>* left = nullptr;
    ASTree<V>* right = nullptr;

    static V evalASNode(ASTree<V>* node)
    {
        if (!node->is_terminal)
        {
            assert (node->left != nullptr);
            assert (node->right != nullptr);
        }

        if (node->is_terminal)
        {
            return node->value;
        }

        switch(node->op)
        {
        case Sum  :
            return evalASNode(node->left) + evalASNode(node->right);
        case Subtract  :
            return evalASNode(node->left) - evalASNode(node->right);
        case Multiply  :
            return evalASNode(node->left) * evalASNode(node->right);
        case Divide  :
            return evalASNode(node->left) / evalASNode(node->right);
        }

        throw "Impossible";
    }
};

template<typename V>
ASTree<V>::~ASTree() {}

template<typename V>
ASTree<V>::ASTree(operation op)
{
    this->op = op;
    this->is_terminal = false;
}

template<typename V>
ASTree<V>::ASTree(V v)
{
    this->value = v;
    this->is_terminal = true;
}

template<typename V>
ASTree<V>* ASTree<V>::addLNonTerminal(operation op)
{
    assert (this->left == nullptr);
    ASTree<V>* newNode = new ASTree(op);

    this->left = newNode;

    return newNode;
}

template<typename V>
void ASTree<V>::addLTerminal(V v)
{
    assert (this->left == nullptr);
    ASTree<V>* newNode = new ASTree(v);

    this->left = newNode;
}

template<typename V>
ASTree<V>* ASTree<V>::addRNonTerminal(operation op)
{
    assert (this->right == nullptr);
    ASTree<V>* newNode = new ASTree(op);

    this->right = newNode;

    return newNode;
}

template<typename V>
void ASTree<V>::addRTerminal(V v)
{
    assert (this->right == nullptr);
    ASTree<V>* newNode = new ASTree(v);

    this->right = newNode;
}

template<typename V>
V ASTree<V>::eval()

{
    return ASTree::evalASNode(this);
}
