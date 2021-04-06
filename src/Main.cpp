#include "DoubleLinkedList.h"
#include "Token.h"
#include "AST.h"

int main()
{
    DoubleLinkedList<Token> ls;

    Token tk0("foo", D);
    Token tk1("bar", B);
    Token tk2("dood", A);
    Token tk3("duh", C);

    ls.insertSorted(tk0);
    ls.insertSorted(tk1);
    ls.insertSorted(tk2);
    ls.insertSorted(tk3);

    for (Token tk : ls)
    {
        std::cout << tk << std::endl;
    }

    std::cout << ls.length() << std::endl;

    return 0;
}
