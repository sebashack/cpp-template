// #include "Bar.cpp"
#include "LinkedList.h"
#include "Person.h"

int main()
{
    LinkedList<int> l;

    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    std::cout << "Val " << l.pop() << std::endl;
    std::cout << "Val " << l.pop() << std::endl;
    std::cout << "Val " << l.pop() << std::endl;
    std::cout << "Val " << l.pop() << std::endl;
    std::cout << "Val " << l.pop() << std::endl;

    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);

    //std::cout << "Val " << l.pop() << std::endl;
    //std::cout << "Val " << l.pop() << std::endl;
    //std::cout << "Val " << l.pop() << std::endl;
    //std::cout << "Val " << l.pop() << std::endl;
    //std::cout << "Val " << l.pop() << std::endl;

    l.print();

    //Person p("Sebastian", 1.81, 68.0);
    //Person* p = new Person("Sebastian", 1.81, 68.0);
    //p->printName();
    //p->printHeight();
    //p->printWeight();
    //delete p;

    //Bar bar;
    //bar.str = "boooo !!!!";
    //bar.do_something();

    //char v[6] = {'a', 'b', 'c', 'd','e', 'f'};
    //char* p = &v[3];

    //std::cout << "Both are the same: " << p[1] << " " << *(p + 1) << std::endl;
    //printChar(p[1]);

    return 0;
}
