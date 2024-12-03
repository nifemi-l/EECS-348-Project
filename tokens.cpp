#include "tokens.h"

// Constructor for tokens with a value (e.g., NUMBER)
Token::Token(TokenType type, const std::string &value) : type(type), value(value) {}

// Constructor for tokens without a value
Token::Token(TokenType type) : type(type), value("") {}

// Helper function to get the token type as a string
std::string Token::tokenTypeName(TokenType type) const
{
    switch (type)
    {
    case TokenType::NUMBER:
        return "NUMBER";
    case TokenType::PLUS:
        return "PLUS";
    case TokenType::MINUS:
        return "MINUS";
    case TokenType::MULTIPLY:
        return "MULTIPLY";
    case TokenType::DIVIDE:
        return "DIVIDE";
    case TokenType::MODULUS:
        return "MODULUS";
    case TokenType::EXPONENT:
        return "EXPONENT";
    case TokenType::LPAREN:
        return "LPAREN";
    case TokenType::RPAREN:
        return "RPAREN";
    default:
        return "UNKNOWN";
    }
}

// Convert the token to a string representation
std::string Token::toString() const
{
    if (type == TokenType::NUMBER)
    {
        return "NUMBER(" + value + ")";
    }
    return tokenTypeName(type);
}
