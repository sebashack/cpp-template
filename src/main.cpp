#include "foo.h"
#include "bar.cpp"

int main()
{
    Foo foo;
    foo.str = "!!!! #### --- #### --- #### !!!!";
    foo.do_something();

    Bar bar;
    bar.str = "boooo !!!!";
    bar.do_something();

    return 0;
}
