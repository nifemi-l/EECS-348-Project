#ifndef TOKENS_H
#define TOKENS_H

#include <string>

// Define token types using scoped enumeration
enum class TokenType
{
    NUMBER,   // '0-9'
    PLUS,     // '+'
    MINUS,    // '-'
    MULTIPLY, // '*'
    DIVIDE,   // '/'
    MODULUS,  // '%'
    EXPONENT, // '**'
    LPAREN,   // '('
    RPAREN    // ')'
};

class Token
{
public:
    TokenType type;    // Token type
    std::string value; // Token value (used for NUMBER tokens)

    // Constructor for tokens with a value (e.g., NUMBER)
    Token(TokenType type, const std::string &value);

    // Constructor for tokens without a value
    Token(TokenType type);

    // Convert the token to a string representation
    std::string toString() const;

private:
    // Helper function to get the token type as a string
    std::string tokenTypeName(TokenType type) const;
};

#endif // TOKENS_H
