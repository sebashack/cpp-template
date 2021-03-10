#include <iostream>
#include "foo.h"


void Foo::do_something()
{
  std::cout << "Doing something!" << this->str << std::endl;
}
