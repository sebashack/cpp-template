#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "DoubleLinkedList.h"

enum word_type { Subject, Verb, Predicate };

std::ostream& operator<< (std::ostream& o, word_type const& tt);

using ushort = unsigned short int;
using word_count = std::map<word_type, size_t>;

class Word
{
public:
    word_type type;
    std::string value;
    ushort frequency;

    Word(std::string value, word_type type, ushort frequency);
    Word() = default;
    ~Word();

    void increaseFrequency();

    bool operator<(const Word& tk) const;
    friend std::ostream& operator<< (std::ostream& o, Word const& tk);

private:
};

word_count readWords(std::string filename, DoubleLinkedList<Word>& words);
intmax_t searchByType(word_type type, DoubleLinkedList<Word>& words);
word_type charToWordType(char c);
