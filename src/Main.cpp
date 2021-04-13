#include "AST.h"

int main()
{

    ASTree<int>* root = new ASTree<int>(Sum);

    ASTree<int>* l0 = root->addLNonTerminal(Multiply);
    ASTree<int>* l1 = l0->addLNonTerminal(Divide);
    l1->addLTerminal(16);
    l1->addRTerminal(2);
    l0->addRTerminal(3);

    ASTree<int>* r1 = root->addRNonTerminal(Sum);
    r1->addLTerminal(3);
    r1->addRTerminal(8);

    std::cout << root->eval() << std::endl;

    return 0;
}
