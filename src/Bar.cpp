#include <iostream>
#include <string>


class Bar
{

public:
    std::string str;
    void do_something()
    {
        std::cout << "Doing something!" << this->str << std::endl;
    }
};
