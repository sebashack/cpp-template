#include <cmath>
#include <iostream>

#include "Word.h"

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
