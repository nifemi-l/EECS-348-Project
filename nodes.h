#ifndef AST_NODES_H
#define AST_NODES_H

#include <string>

// Abstract base class for all AST nodes
class Node
{
public:
    virtual ~Node() = default;
    virtual std::string repr() const = 0; // Return string representation of the node
};

// Node for numeric values
class NumberNode : public Node
{
private:
    double value;

public:
    explicit NumberNode(double value);
    double getValue() const;
    std::string repr() const override;
};

// Base class for binary operations
class BinaryNode : public Node
{
protected:
    Node *left;
    Node *right;

public:
    BinaryNode(Node *left, Node *right);
    virtual ~BinaryNode();
    Node *getLeft() const;
    Node *getRight() const;
};

// Addition Node
class AddNode : public BinaryNode
{
public:
    AddNode(Node *left, Node *right);
    std::string repr() const override;
};

// Subtraction Node
class SubtractNode : public BinaryNode
{
public:
    SubtractNode(Node *left, Node *right);
    std::string repr() const override;
};

// Multiplication Node
class MultiplyNode : public BinaryNode
{
public:
    MultiplyNode(Node *left, Node *right);
    std::string repr() const override;
};

// Division Node
class DivideNode : public BinaryNode
{
public:
    DivideNode(Node *left, Node *right);
    std::string repr() const override;
};

// Modulus Node
class ModulusNode : public BinaryNode
{
public:
    ModulusNode(Node *left, Node *right);
    std::string repr() const override;
};

// Exponentiation Node
class ExponentNode : public BinaryNode
{
public:
    ExponentNode(Node *left, Node *right);
    std::string repr() const override;
};

// Base class for unary operations
class UnaryNode : public Node
{
protected:
    Node *node;

public:
    explicit UnaryNode(Node *node);
    virtual ~UnaryNode();
    Node *getNode() const;
};

// Unary Plus Node
class PlusNode : public UnaryNode
{
public:
    explicit PlusNode(Node *node);
    std::string repr() const override;
};

// Unary Minus Node
class MinusNode : public UnaryNode
{
public:
    explicit MinusNode(Node *node);
    std::string repr() const override;
};

#endif // AST_NODES_H
