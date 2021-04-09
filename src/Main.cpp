#include "DoubleLinkedList.h"
#include "Word.h"

int main()
{
    DoubleLinkedList<Word> ls;

    Word tk0("foo", Subject);
    Word tk1("bar", Verb);
    Word tk2("dood", Predicate);

    ls.insertSorted(tk0);
    ls.insertSorted(tk1);
    ls.insertSorted(tk2);

    for (Word tk : ls)
    {
        std::cout << tk << std::endl;
    }

    std::cout << ls.length() << std::endl;

    return 0;
}
