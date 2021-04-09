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

std::ostream& operator<< (std::ostream& o, Word const& tk)
{
    return o << "Word(" << tk.value << ", " << tk.type << ")";
}

bool Word::operator<(const Word& other) const
{
    return this->type < other.type;
}
