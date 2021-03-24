// #include "Bar.cpp"
#include "LinkedList.h"
#include "Person.h"

int main()
{
    LinkedList<Person> ls;

    Person p0("Sebastian", 1.81, 68.0);
    Person p1("Marco", 1.81, 68.0);
    Person p2("Edison", 1.81, 68.0);
    Person p3("Richard", 1.81, 68.0);

    ls.insert(p0);
    ls.insert(p1);
    ls.insert(p2);
    ls.insert(p3);

    ls.push(p0);
    ls.push(p1);
    ls.push(p2);
    ls.push(p3);

    for (auto it = ls.begin(), end = ls.end(); it != end; ++it)
    {
        std::cout << *it << std::endl;
    }

    for (auto it = ls.begin(), end = ls.end(); it != end; ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
