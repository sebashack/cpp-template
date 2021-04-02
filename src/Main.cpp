// #include "Bar.cpp"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Person.h"

int main()
{
    //DoubleLinkedList<Person> ls;

    //Person p0("Sebastian", 1.81, 68.0);
    //Person p1("Marco", 1.81, 68.0);
    //Person p2("Edison", 1.81, 68.0);
    //Person p3("Richard", 1.81, 68.0);

    //ls.pushBack(p0);
    //ls.pushBack(p1);
    //ls.pushBack(p2);
    //ls.pushBack(p3);

    //std::cout << ls.length() << std::endl;

    //for (auto it = ls.begin(), end = ls.end(); it != end; ++it)
    //{
    //    std::cout << *it << std::endl;
    //}


    //std::cout << ls.getAt(0) << std::endl;
    //std::cout << ls.getAt(1) << std::endl;
    //std::cout << ls.getAt(2) << std::endl;
    //std::cout << ls.getAt(3) << std::endl;

    //ls.insertAt(p3, 1);
    //std::cout << *(ls.removeAt(1)) << std::endl;
    //ls.insertAt(p3, 3);
    //std::cout << *(ls.removeAt(3)) << std::endl;
    //ls.insertAt(p0, 4);
    //std::cout << *(ls.removeAt(4)) << std::endl;

    //ls.getMutAt(0)->update(p3);

    //std::cout << "####" << std::endl;

    //for (Person p : ls)
    //{
    //    std::cout << p << std::endl;
    //}

    //std::cout << *(ls.pop()) << std::endl;
    //std::cout << *(ls.popLast()) << std::endl;
    //std::cout << *(ls.pop()) << std::endl;
    //std::cout << *(ls.popLast()) << std::endl;

    //std::cout << ls.length() << std::endl;

    DoubleLinkedList<char> ls;
    char a0 = 'x';
    char a1 = 'a';
    char a2 = 'e';
    char a3 = 's';
    char a4 = 'n';
    char a5 = 'q';
    char a6 = 'p';
    char a7 = 'm';
    char a8 = 'x';
    char a9 = 'f';
    char a10 = 'm';
    char a11 = 'z';

    ls.insertSorted(a0);
    ls.insertSorted(a1);
    ls.insertSorted(a2);
    ls.insertSorted(a3);
    ls.insertSorted(a4);
    ls.insertSorted(a5);
    ls.insertSorted(a6);
    ls.insertSorted(a7);
    ls.insertSorted(a8);
    ls.insertSorted(a9);
    ls.insertSorted(a10);
    ls.insertSorted(a11);

    for (char n : ls)
    {
        std::cout << n << std::endl;
    }

    std::cout << ls.length() << std::endl;

    return 0;
}
