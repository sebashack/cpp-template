#include <time.h>

#include "DoubleLinkedList.h"
#include "Word.h"


int main()
{
    DoubleLinkedList<Word> words;
    word_count count = readWords("/home/sebastian/university/programming_languages/cpp_template/sample-words.txt", words);


    short generatedSentences = 0;
    words.shuffle();

    while (generatedSentences <= MAX_WORDS && words.length() > 0)
    {
        std::cerr << generatedSentences + 1 << ") ";
        processWord(words, count, Subject);
        processWord(words, count, Verb);
        processWord(words, count, Predicate);

        ++generatedSentences;
    }

    return 0;
}
