#include <string>

#include "Generator.h"
#include "Words.h"


Generator::~Generator() {}

Generator::Generator(std::string path)
{
    Words words(path);

    this->words = words;
    this->words.readWords();
    this->words.shuffle();
}

void Generator::printSentences()
{
    short generatedSentences = 0;

    while (generatedSentences < MAX_WORDS && this->words.length() > 0)
    {
        if (generatedSentences < 9)
        {
            std::cout << 0 << generatedSentences + 1 << "| ";
        }
        else
        {
            std::cout << generatedSentences + 1 << "| ";
        }

        this->words.useWordType(Subject);
        this->words.useWordType(Verb);
        this->words.useWordType(Predicate);

        ++generatedSentences;
    }

    // Reset after printing so that we can reuse the generator.
    this->words.reset();
    this->words.shuffle();
}
