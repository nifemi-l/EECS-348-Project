#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

// define token types
enum class TokenType{
    NUMBER,   //0-9 integers
    PLUS,     // '+'
    MINUS,    // '-'
    MULTIPLY, // '*'
    DIVIDE,   // '/'
    MODULUS,  // '%'
    EXPONENT, // '**'
    LPAREN,   // '('
    RPAREN    // ')'
};

struct Token {
    TokenType type;
    string value = "";

    // initializer
    // Token::Token(TokenType type, string value)
    //     : type(type), value(value)
    // {}
    
    // MOD: remove extra qualification since definition is within scope of Token
    Token(TokenType type, string value)
    : type(type), value(value)
    {}

    // tokens that do not have a number 
    Token(TokenType type)
        : Token(type, "") {}



    public:
        // returns name of token and value, if it is a number
        // string toString(){
        //     string repr = tokenTypeName(type) + value;
        //     return repr;
        // }

        // MOD: add space for clarity
        string toString(){
            string repr = tokenTypeName(type) + ' ' + value;
            return repr;
        }


    private:
        // returns the token type as a string
        string tokenTypeName(TokenType type){
            switch (type) {
                case TokenType::NUMBER:   return "NUMBER";
                case TokenType::PLUS:     return "PLUS";
                case TokenType::MINUS:    return "MINUS";
                case TokenType::MULTIPLY: return "MULTIPLY";
                case TokenType::DIVIDE:   return "DIVIDE";
                case TokenType::MODULUS:  return "MODULUS";
                case TokenType::EXPONENT: return "EXPONENT";
                case TokenType::LPAREN:   return "LPAREN";
                case TokenType::RPAREN:   return "RPAREN";
                default:                  return "UNKNOWN";
            }
        }
};

