#include <iostream>

#include "Token.h"


std::ostream& operator<< (std::ostream& o, token_type const& tt)
{
    std::string rep;

    switch(tt)
    {
    case A:
        rep = "A";
        break;
    case B:
        rep = "B";
        break;
    case C:
        rep = "C";
        break;
    case D:
        rep = "D";
        break;
    }

    return o << rep;
}

Token::Token(std::string value, token_type type)
{
    this->value = value;
    this->type = type;
}

Token::~Token() {}

std::ostream& operator<< (std::ostream& o, Token const& tk)
{
    return o << "Token(" << tk.value << ", " << tk.type << ")";
}
