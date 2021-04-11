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

Word::Word(std::string value, word_type type)
{
    this->value = value;
    this->type = type;
}

Word::~Word() {}

std::ostream& operator<< (std::ostream& o, Word const& w)
{
    return o << "Word(" << w.value << ", " << w.type << ", " << w.frequency << ")";
}

// Compare words by frequency
bool Word::operator<(const Word& other) const
{
    return this->frequency < other.frequency;
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

    if(in.peek() < 0)
    {
        std::cerr << "WARNING!: Cannot open the File `" << filename << "`" << std::endl;
        exit (EXIT_FAILURE);
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

            Word w(word, type);
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

std::tuple<word_type, word_type> pickOutWordType(word_count& count, word_type type0, word_type type1)
{
    size_t c0 = count[type0];
    size_t c1 = count[type1];

    if (c0 >= c1)
    {
        return std::make_tuple(type0, type1);
    }
    else
    {
        return std::make_tuple(type1, type0);
    }
}

void useWordType(DoubleLinkedList<Word> &words, word_count& count, word_count& removalCount, word_type type)
{
    while (words.length() > 0)
    {
        intmax_t wordIndex = searchByType(type, words);

        if (count[type] > 0 && wordIndex > -1)
        {
            Word& word = words.getAt(wordIndex);
            short maxWordFreq;

            if (count[type] >= CEILING_THRESHOLD)
            {
                maxWordFreq = ceil(static_cast<float>(MAX_WORDS) / count[type]);
            }
            else
            {
                maxWordFreq = round(static_cast<float>(MAX_WORDS) / count[type]);
            }

            // Edge case when we are running out of a type of word.
            // This happens, for example, if we have a list with 28 subjects,
            // 1 verb and 1 predicate. In that case it is impossible to generate 30
            // different sentences so duplcation is allowed there.
            if (removalCount[type] == 1)
            {
                word.printWordInSentence();
                break;
            }

            if (word.frequency >= maxWordFreq)
            {
                words.removeAt(wordIndex);
                --removalCount[type];
            }
            else
            {
                word.printWordInSentence();
                word.increaseFrequency();

                std::tuple<word_type, word_type> t0 = pickOutWordType(count, Subject, Predicate);
                std::tuple<word_type, word_type> t1 = pickOutWordType(count, Verb, std::get<1>(t0));

                if (type == std::get<0>(t0) || type == std::get<0>(t1))
                {
                    Word* word = words.removeAt(wordIndex);
                    words.pushBack(*word);
                }

                break;
            }
        }
    }
}
