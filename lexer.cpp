#include <vector>
#include <cctype>
#include <stdexcept>
#include "lexer.h"  // Include lexer header
#include "tokens.h" // Include tokens header

using namespace std;

// Constructor to initialize the lexer with input
Lexer::Lexer(const string &input) : text(input), pos(0), current_char(input[0]) {}

// Move to the next character in the input
void Lexer::advance()
{
    pos++;
    current_char = (pos < text.size()) ? text[pos] : '\0';
}

// Generate a NUMBER token
Token Lexer::generateNum()
{
    string number_str;

    // Loop to read digits or decimal point
    while (isdigit(current_char) || current_char == '.')
    {
        number_str += current_char;
        advance();
    }

    return Token(TokenType::NUMBER, number_str);
}

// Generate a list of tokens from the input string
vector<Token> Lexer::generateTokens()
{
    vector<Token> tokens;

    while (current_char != '\0')
    {
        if (isspace(current_char))
        {
            advance();
        }
        else if (isdigit(current_char) || current_char == '.')
        {
            tokens.push_back(generateNum());
        }
        else if (current_char == '+')
        {
            tokens.push_back(Token(TokenType::PLUS));
            advance();
        }
        else if (current_char == '-')
        {
            tokens.push_back(Token(TokenType::MINUS));
            advance();
        }
        else if (current_char == '*')
        {
            advance();
            if (current_char == '*')
            {
                tokens.push_back(Token(TokenType::EXPONENT));
                advance();
            }
            else
            {
                tokens.push_back(Token(TokenType::MULTIPLY));
            }
        }
        else if (current_char == '/')
        {
            tokens.push_back(Token(TokenType::DIVIDE));
            advance();
        }
        else if (current_char == '%')
        {
            tokens.push_back(Token(TokenType::MODULUS));
            advance();
        }
        else if (current_char == '(')
        {
            tokens.push_back(Token(TokenType::LPAREN));
            advance();
        }
        else if (current_char == ')')
        {
            tokens.push_back(Token(TokenType::RPAREN));
            advance();
        }
        else
        {
            throw ErrorHandling("Illegal character: " + string(1, current_char));
        }
    }

    return tokens;
}
