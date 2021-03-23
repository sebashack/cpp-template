#pragma once

#include <string>

class Person
{

public:
    Person(std::string name, float height, float weight);
    Person() = default;
    ~Person();

    std::string name;
    float height;
    float weight;

    void setName(std::string name);
    void setHeight(float height);
    void setWeight(float weight);

    void printName();
    void printHeight();
    void printWeight();
private:
};
