#include "Foo.h"
#include "Bar.cpp"

void printChar(char& c)
{
    std::cout << c << std::endl;
}

int main()
{
    Foo foo;
    foo.str = "!!!! #### --- #### --- #### !!!!";
    foo.do_something();

    Bar bar;
    bar.str = "boooo !!!!";
    bar.do_something();

    char v[6] = {'a', 'b', 'c', 'd','e', 'f'};
    char* p = &v[3];


    std::cout << "Both are the same: " << p[1] << " " << *(p + 1) << std::endl;
    printChar(p[1]);

    return 0;
}
