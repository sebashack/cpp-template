#include "Person.h"
#include "Bar.cpp"

void printChar(char& c)
{
    std::cout << c << std::endl;
}

int main()
{
    Person p("Sebastian", 1.81, 68.0);
    p.printName();
    p.printHeight();
    p.printWeight();
    // delete &p; -- Try different versions of c++

    //Bar bar;
    //bar.str = "boooo !!!!";
    //bar.do_something();

    //char v[6] = {'a', 'b', 'c', 'd','e', 'f'};
    //char* p = &v[3];


    //std::cout << "Both are the same: " << p[1] << " " << *(p + 1) << std::endl;
    //printChar(p[1]);

    return 0;
}
