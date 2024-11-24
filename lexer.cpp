#include <stdio.h>
#include <vector> // dynamic arrays to store elems
#include <cctype> // char handling functions
#include <stdexcept> // throw error(s)
#include "tokens.cpp" // token, tokenType

using namespace std;

class Lexer {
private:
    string text;
    size_t pos; // index in input
    char current_char; // char at current pos

    // define a function to move to the next char in string
    void advance() {
        pos++;
        // if within bounds, set to next char, else set to null char for end of input
        current_char = (pos < text.size()) ? text[pos] : '\0';
    }

    // define a function to generate NUMBER token
    Token generateNum() { 
        string number_str;
        
        // loop to read digits or decimal point
        while (isdigit(current_char) || current_char == '.') {
            number_str += current_char; // construct number
            advance(); 
        }

        // return NUMBER token w/ constructed num as value
        return Token(TokenType::NUMBER, number_str);
    }

public:
    // constructor to init lexer and member variables
    Lexer(string input) : text(input), pos(0), current_char(input[0]) {}

    // define a function to generate a list of tokens from input string
    vector<Token> generateTokens() { 
        // create a vector to store tokens
        vector<Token> tokens; 

        // loop through input, assigning appropriate tokens
        while (current_char != '\0') { 
            if (isspace(current_char)) { // whitespace
                advance();
            } else if (isdigit(current_char) || current_char == '.') { // digit/decimal
                // generate NUMBER token, add to the list
                tokens.push_back(generateNum());
            } else if (current_char == '+') { // addition symbol
                // add PLUS token list
                tokens.push_back(Token(TokenType::PLUS));
                advance();
            } else if (current_char == '-') { 
                tokens.push_back(Token(TokenType::MINUS));
                advance();
            } else if (current_char == '*') { 
                // move to the next character to check for another *
                advance();
                if (current_char == '*') { // exponent token
                    tokens.push_back(Token(TokenType::EXPONENT));
                    advance();
                } else {
                    tokens.push_back(Token(TokenType::MULTIPLY));
                    // no advance, offset earlier advance
                }
            } else if (current_char == '/') { 
                tokens.push_back(Token(TokenType::DIVIDE));
                advance();
            } else if (current_char == '%') { 
                tokens.push_back(Token(TokenType::MODULUS));
                advance();
            } else if (current_char == '(') { 
                tokens.push_back(Token(TokenType::RPAREN));
                advance();
            } else if (current_char == ')') { 
                tokens.push_back(Token(TokenType::LPAREN));
                advance();
            } else { // invalid char
                // convert the char to a string to allow for concatenation, repeat once
                throw runtime_error("Illegal character: " + string(1, current_char));
            }
        }
        // return list of generated tokens
        return tokens;
    }
};

// Uncomment to test

// int main() { 
//     string input = "12 + 34 * (5 - 6.7) ** 2";
//     Lexer lexer(input); // create lexer obj

//     try { 
//         vector<Token> tokens = lexer.generateTokens();

//         // print tokens in list using automatic deduction (compiler determines type)
//         for (auto& token : tokens) { 
//             cout << token.toString() << endl;
//         } 
//     } catch (const exception& e) { 
//         // unbuffered error stream, print error
//         cerr << e.what() << endl;
//     }

//     return 0;
// }