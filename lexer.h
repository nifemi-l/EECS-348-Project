#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include "tokens.h"

class Lexer
{
private:
    std::string text;
    size_t pos;
    char current_char;

    void advance();
    Token generateNum();

public:
    explicit Lexer(const std::string &input);
    std::vector<Token> generateTokens();
};

#endif // LEXER_H
