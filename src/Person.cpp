#include <iostream>

#include "Person.h"

Person::Person(std::string name, float height, float weight)
{
    this->name = name;
    this->height = height;
    this->weight = weight;
}

Person::~Person() {}

std::ostream& operator<< (std::ostream& o, Person const& p)
{
    return o << p.name;
}

void Person::setName(std::string name)
{
    this->name = name;
}

void Person::setHeight(float height)
{
    this->height = height;
}

void Person::setWeight(float weight)
{
    this->weight = weight;
}

void Person::printName()
{
    std::cout << this->name << std::endl;
}

void Person::printHeight()
{
    std::cout << this->height << std::endl;
}

void Person::printWeight()
{
    std::cout << this->weight << std::endl;
}
