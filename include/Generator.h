#pragma once

#include <string>

#include "Words.h"

class Generator
{
public:
    Generator(std::string path);
    ~Generator();

    void printSentences();

private:
    Words words;
};
