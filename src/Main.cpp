#include "DoubleLinkedList.h"
#include "Word.h"
#include "Words.h"


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " WORDS_FILEPATH" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];
    Words words(filepath);

    words.readWords();

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

        words.useWordType(Subject);
        words.useWordType(Verb);
        words.useWordType(Predicate);

        ++generatedSentences;
    }

    return 0;
}
