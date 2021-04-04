#pragma once
#include <iostream>
#include <string>

enum token_type {  A, B, C, D };

std::ostream& operator<< (std::ostream& o, token_type const& tt);

class Token
{
public:
    std::string value;
    token_type type;

    Token(std::string value, token_type type);
    Token() = default;
    ~Token();


    friend std::ostream& operator<< (std::ostream& o, Token const& tk);

private:
};
