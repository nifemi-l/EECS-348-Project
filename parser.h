#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <stdexcept>
#include "tokens.h"
#include "nodes.h"
#include "errorhandling.h"

class Parser
{
private:
    const std::vector<Token> &tokens; // Reference to the tokens vector
    size_t pos;                       // Current position in the tokens vector
    const Token *current_token;       // Pointer to the current token

    // Advances to the next token
    void advance();

    // Raises a syntax error
    void raise_error() const;

    // Parses addition and subtraction
    Node *expression();

    // Parses multiplication, division, and modulus
    Node *term();

    // Parses exponentiation
    Node *factor();

    // Parses numbers, parentheses, and unary operators
    Node *primary();

public:
    // Constructor initializes the parser with a reference to tokens
    explicit Parser(const std::vector<Token> &tokens);

    // Parses the entire input and returns the root of the AST
    Node *parse();
};

#endif // PARSER_H
