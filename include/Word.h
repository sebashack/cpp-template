#pragma once
#include <iostream>
#include <string>

enum word_type { Subject, Verb, Predicate };

class Word
{
public:
    std::string value;
    word_type type;

    Word(std::string value, word_type type);
    Word() = default;
    ~Word();

    bool operator<(const Word& tk) const;
    friend std::ostream& operator<< (std::ostream& o, Word const& tk);

private:
};

std::ostream& operator<< (std::ostream& o, word_type const& tt);
