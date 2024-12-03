#include "parser.h"

// Constructor
Parser::Parser(const std::vector<Token> &tokens) : tokens(tokens), pos(0)
{
    current_token = tokens.empty() ? nullptr : &tokens[0];
}

// Advances to the next token
void Parser::advance()
{
    if (pos < tokens.size() - 1)
    {
        pos++;
        current_token = &tokens[pos];
    }
    else
    {
        current_token = nullptr;
    }
}

// Raises a syntax error
void Parser::raise_error() const
{
    throw ErrorHandling("Syntax Error at token position " + std::to_string(pos));
}

// Parses addition and subtraction
Node *Parser::expression()
{
    Node *node = term();
    while (current_token && (current_token->type == TokenType::PLUS || current_token->type == TokenType::MINUS))
    {
        Token op = *current_token;
        advance();
        if (op.type == TokenType::PLUS)
            node = new AddNode(node, term());
        else
            node = new SubtractNode(node, term());
    }
    return node;
}

// Parses multiplication, division, and modulus
Node *Parser::term()
{
    Node *node = factor();
    while (current_token && (current_token->type == TokenType::MULTIPLY || current_token->type == TokenType::DIVIDE || current_token->type == TokenType::MODULUS))
    {
        Token op = *current_token;
        advance();
        if (op.type == TokenType::MULTIPLY)
            node = new MultiplyNode(node, factor());
        else if (op.type == TokenType::DIVIDE)
            node = new DivideNode(node, factor());
        else
            node = new ModulusNode(node, factor());
    }
    return node;
}

// Parses exponentiation
Node *Parser::factor()
{
    Node *node = primary();
    while (current_token && current_token->type == TokenType::EXPONENT)
    {
        advance();
        node = new ExponentNode(node, primary());
    }
    return node;
}

// Parses numbers, parentheses, and unary operators
Node *Parser::primary()
{
    if (!current_token)
        raise_error();

    if (current_token->type == TokenType::NUMBER)
    {
        Node *node = new NumberNode(std::stod(current_token->value));
        advance();
        return node;
    }
    else if (current_token->type == TokenType::LPAREN)
    {
        advance();
        Node *node = expression();
        if (!current_token || current_token->type != TokenType::RPAREN)
            raise_error();
        advance();
        return node;
    }
    else if (current_token->type == TokenType::PLUS)
    {
        advance();
        return new PlusNode(primary());
    }
    else if (current_token->type == TokenType::MINUS)
    {
        advance();
        return new MinusNode(primary());
    }

    raise_error();
    return nullptr; // Unreachable
}

// Parses the entire input and returns the root of the AST
Node *Parser::parse()
{
    return expression();
}
