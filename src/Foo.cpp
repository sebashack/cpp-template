#include <iostream>
#include "Foo.h"


void Foo::do_something()
{
    std::cout << "Doing something!" << this->str << std::endl;
}
