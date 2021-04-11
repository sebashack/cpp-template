#pragma once

#include <string>

#include "Word.h"

class Words
{
public:
    Words(std::string path) : dictpath(path) {};
    Words() = default;
    ~Words();

    intmax_t searchByType(word_type type);
    size_t length();
    void readWords();
    void shuffle();
    void useWordType(word_type type);

private:
    std::string dictpath;
    DoubleLinkedList<Word> words;
    word_count wCount = { { Subject, 0 }, { Verb, 0 }, { Predicate, 0 } };
    word_count removalCount = { { Subject, 0 }, { Verb, 0 }, { Predicate, 0 } };
};
