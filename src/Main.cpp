#include "DoubleLinkedList.h"
#include "Word.h"


int main()
{
    // DoubleLinkedList<Word> ls;

    Word tk0("hola", Subject, 1);
    Word tk1("mundo", Subject, 1);
    Word tk2("como", Subject, 1);
    Word tk3("estas", Subject, 1);

    // tk0.increaseFrequency();

    // ls.insertSorted(tk0);
    // ls.insertSorted(tk1);
    // ls.insertSorted(tk2);

    // for (Word tk : ls)
    // {
    //     std::cout << tk << std::endl;
    // }

    // std::cout << ls.length() << std::endl;

    DoubleLinkedList<Word> words;
    readWords("/home/sebastian/university/programming_languages/cpp_template/words.txt", words);
    //DoubleLinkedList<Word> words;
    //std::cout << words.length() << std::endl;

    for (Word w : words)
    {
        std::cout << w << std::endl;
    }

    return 0;
}
