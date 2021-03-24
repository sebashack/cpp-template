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

    std::cout << ls.length() << std::endl;

    //for (auto it = ls.begin(), end = ls.end(); it != end; ++it)
    //{
    //    std::cout << *it << std::endl;
    //}


    //std::cout << ls.getAt(0) << std::endl;
    //std::cout << ls.getAt(1) << std::endl;
    //std::cout << ls.getAt(2) << std::endl;
    //std::cout << ls.getAt(3) << std::endl;

    ls.insertAt(p3, 1);
    std::cout << *(ls.removeAt(1)) << std::endl;
    ls.insertAt(p3, 3);
    std::cout << *(ls.removeAt(3)) << std::endl;
    ls.insertAt(p0, 4);
    std::cout << *(ls.removeAt(4)) << std::endl;

    std::cout << "####" << std::endl;

    for (Person p : ls)
    {
        std::cout << p << std::endl;
    }

    //std::cout << *(ls.pop()) << std::endl;
    //std::cout << *(ls.popLast()) << std::endl;
    //std::cout << *(ls.pop()) << std::endl;
    //std::cout << *(ls.popLast()) << std::endl;

    std::cout << ls.length() << std::endl;

    return 0;
}
