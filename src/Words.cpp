#include <cmath>
#include <fstream>
#include <iostream>

#include "Word.h"
#include "Words.h"
#include "DoubleLinkedList.h"

Words::~Words() {}

void Words::readWords()
{
    std::ifstream in(this->dictpath.c_str());

    if(in.peek() < 0)
    {
        std::cerr << "WARNING!: Cannot open the File `" << this->dictpath << "`" << std::endl;
        exit (EXIT_FAILURE);
    }

    std::string line;
    short i = 0;

    while (std::getline(in, line) && i <= MAX_WORDS)
    {
        if(line.size() > 0)
        {
            std::string delimiter = ":";
            std::string charType = line.substr(0, line.find(delimiter));
            std::string word = line.substr(line.find(delimiter) + 1, line.length());

            word_type type = charToWordType(charType.front());
            this->wCount[type]++;
            this->removalCount[type]++;

            Word w(word, type);
            this->words.insertSorted(w);
        }

        ++i;
    }

    in.close();
}

void Words::shuffle()
{
    this->words.shuffle();
}

size_t Words::length()
{
    return this->words.length();
}

intmax_t Words::searchByType(word_type type)
{
    size_t i = 0;

    for (Word w : this->words)
    {
        if (w.type == type)
        {
            return i;
        }

        ++i;
    }

    return -1;
}

void Words::useWordType(word_type type)
{
    while (this->words.length() > 0)
    {
        intmax_t wordIndex = this->searchByType(type);

        if (wCount[type] > 0 && wordIndex > -1)
        {
            Word& word = this->words.getAt(wordIndex);
            short maxWordFreq;

            if (this->wCount[type] >= CEILING_THRESHOLD)
            {
                maxWordFreq = ceil(static_cast<float>(MAX_WORDS) / this->wCount[type]);
            }
            else
            {
                maxWordFreq = round(static_cast<float>(MAX_WORDS) / this->wCount[type]);
            }

            // Edge case when we are running out of a type of word.
            // This happens, for example, if we have a list with 28 subjects,
            // 1 verb and 1 predicate. In that case it is impossible to generate 30
            // different sentences so duplcation is allowed there.
            if (this->removalCount[type] == 1)
            {
                word.printWordInSentence();
                break;
            }

            if (word.frequency >= maxWordFreq)
            {
                this->words.removeAt(wordIndex);
                --this->removalCount[type];
            }
            else
            {
                word.printWordInSentence();
                word.increaseFrequency();

                std::tuple<word_type, word_type> t0 = pickOutWordType(this->wCount, Subject, Predicate);
                std::tuple<word_type, word_type> t1 = pickOutWordType(this->wCount, Verb, std::get<1>(t0));

                if (type == std::get<0>(t0) || type == std::get<0>(t1))
                {
                    Word* word = this->words.removeAt(wordIndex);
                    this->words.pushBack(*word);
                }

                break;
            }
        }
    }
}
