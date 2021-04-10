#include <cmath>
#include <fstream>
#include <iostream>

#include "Word.h"
#include "DoubleLinkedList.h"

std::ostream& operator<< (std::ostream& o, word_type const& tt)
{
    std::string rep;

    switch(tt)
    {
    case Subject:
        rep = "Subject";
        break;
    case Verb:
        rep = "Verb";
        break;
    case Predicate:
        rep = "Predicate";
        break;
    }

    return o << rep;
}

Word::Word(std::string value, word_type type, ushort frequency)
{
    this->value = value;
    this->type = type;
    this->frequency = frequency;
}

Word::~Word() {}

std::ostream& operator<< (std::ostream& o, Word const& w)
{
    return o << "Word(" << w.value << ", " << w.type << ", " << w.frequency << ")";
}

bool Word::operator<(const Word& other) const
{
    return this->type < other.type;
}

void Word::increaseFrequency()
{
    this->frequency++;
}

void Word::printWordInSentence()
{
    if (this->type == Predicate)
    {
        std::cout << this->value << "." << std::endl;
    }
    else
    {
        std::cout << this->value << " ";
    }
}

std::map<word_type, size_t> readWords(std::string filename, DoubleLinkedList<Word>& words)
{
    std::ifstream in(filename.c_str());

    if(!in)
    {
        std::cerr << "Cannot open the File : " << filename << std::endl;
        throw "File error";
    }

    std::string line;

    word_count count =
    {
        { Subject, 0 },
        { Verb, 0 },
        { Predicate, 0 }
    };

    short i = 0;

    while (std::getline(in, line) && i <= MAX_WORDS)
    {
        if(line.size() > 0)
        {
            std::string delimiter = ":";
            std::string charType = line.substr(0, line.find(delimiter));
            std::string word = line.substr(line.find(delimiter) + 1, line.length());

            word_type type = charToWordType(charType.front());
            count[type]++;

            Word w(word, type, 1);
            words.insertSorted(w);
        }

        ++i;
    }

    in.close();

    return count;
}

intmax_t searchByType(word_type type, DoubleLinkedList<Word>& words)
{
    size_t i = 0;

    for (Word w : words)
    {
        if (w.type == type)
        {
            return i;
        }

        ++i;
    }

    return -1;
}

word_type charToWordType(char c)
{
    word_type type;

    switch(c)
    {
    case 's':
        type = Subject;
        break;
    case 'v':
        type = Verb;
        break;
    case 'p':
        type = Predicate;
        break;
    }

    return type;
}

void processWord(DoubleLinkedList<Word> &words, word_count& count, word_type type)
{
    if (words.length() > 0)
    {
        size_t min = 0;
        size_t max = words.length() - 1;
        size_t r = min + std::rand() % (max - min + 1);

        intmax_t wordIndex = searchByType(type, words);


        if (count[type] > 0 && wordIndex > -1)
        {
            Word& word = words.getAt(wordIndex);
            short maxWordFreq = round(MAX_WORDS / count[type]);

            word.printWordInSentence();
            word.increaseFrequency();

            if (word.frequency > maxWordFreq)
            {
                words.removeAt(wordIndex);
            }
            else
            {
                words.swapValues(r, wordIndex);
            }
        }
    }
}
