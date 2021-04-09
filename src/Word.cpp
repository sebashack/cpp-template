#include <iostream>
#include <fstream>

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

bool readWords(std::string filename, DoubleLinkedList<Word>& words)
{
    std::ifstream in(filename.c_str());

    if(!in)
    {
        std::cerr << "Cannot open the File : " << filename << std::endl;
        return false;
    }

    std::string line;

    while (std::getline(in, line))
    {
        if(line.size() > 0)
        {
            std::string delimiter = ":";
            std::string type = line.substr(0, line.find(delimiter));
            std::string word = line.substr(line.find(delimiter) + 1, line.length());

            Word w(word, charToWordType(type.front()), 1);
            words.pushBack(w);
        }
    }

    in.close();

    return true;
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
