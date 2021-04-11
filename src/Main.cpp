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
