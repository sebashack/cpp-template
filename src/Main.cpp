// #include "Bar.cpp"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Person.h"

int main()
{
    DoubleLinkedList<Person> ls;

    Person p0("Sebastian", 1.81, 68.0);
    Person p1("Marco", 1.81, 68.0);
    Person p2("Edison", 1.81, 68.0);
    Person p3("Richard", 1.81, 68.0);

    ls.pushBack(p0);
    ls.pushBack(p1);
    ls.pushBack(p2);
    ls.pushBack(p3);

    ls.push(p0);
    ls.push(p1);
    ls.push(p2);
    ls.push(p3);

    std::cout << ls.length() << std::endl;

    for (auto it = ls.begin(), end = ls.end(); it != end; ++it)
    {
        std::cout << *it << std::endl;
    }

    for (Person p : ls)
    {
        std::cout << p << std::endl;
    }

    ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();
    ls.pop();

    std::cout << ls.length() << std::endl;

    return 0;
}
