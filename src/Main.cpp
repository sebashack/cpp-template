#include "DoubleLinkedList.h"
#include "Word.h"


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " WORDS_FILEPATH" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];

    DoubleLinkedList<Word> words;
    word_count count = readWords(filePath, words);
    word_count removalCount =
    {
        { Subject, count[Subject] },
        { Verb, count[Verb] },
        { Predicate, count[Predicate] }
    };

    short generatedSentences = 0;

    words.shuffle();

    while (generatedSentences < MAX_WORDS && words.length() > 0)
    {
        if (generatedSentences < 9)
        {
            std::cout << 0 << generatedSentences + 1 << "| ";
        }
        else
        {
            std::cout << generatedSentences + 1 << "| ";
        }

        useWordType(words, count, removalCount, Subject);
        useWordType(words, count, removalCount, Verb);
        useWordType(words, count, removalCount, Predicate);

        ++generatedSentences;
    }

    return 0;
}
