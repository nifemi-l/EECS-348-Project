#include "nodes.h"

// NumberNode Implementation
NumberNode::NumberNode(double value) : value(value) {}

double NumberNode::getValue() const
{
    return value;
}

std::string NumberNode::repr() const
{
    return std::to_string(value);
}

// BinaryNode Implementation
BinaryNode::BinaryNode(Node *left, Node *right) : left(left), right(right) {}

BinaryNode::~BinaryNode()
{
    delete left;
    delete right;
}

Node *BinaryNode::getLeft() const
{
    return left;
}

Node *BinaryNode::getRight() const
{
    return right;
}

// AddNode Implementation
AddNode::AddNode(Node *left, Node *right) : BinaryNode(left, right) {}

std::string AddNode::repr() const
{
    return "(" + left->repr() + " + " + right->repr() + ")";
}

// SubtractNode Implementation
SubtractNode::SubtractNode(Node *left, Node *right) : BinaryNode(left, right) {}

std::string SubtractNode::repr() const
{
    return "(" + left->repr() + " - " + right->repr() + ")";
}

// MultiplyNode Implementation
MultiplyNode::MultiplyNode(Node *left, Node *right) : BinaryNode(left, right) {}

std::string MultiplyNode::repr() const
{
    return "(" + left->repr() + " * " + right->repr() + ")";
}

// DivideNode Implementation
DivideNode::DivideNode(Node *left, Node *right) : BinaryNode(left, right) {}

std::string DivideNode::repr() const
{
    return "(" + left->repr() + " / " + right->repr() + ")";
}

// ModulusNode Implementation
ModulusNode::ModulusNode(Node *left, Node *right) : BinaryNode(left, right) {}

std::string ModulusNode::repr() const
{
    return "(" + left->repr() + " % " + right->repr() + ")";
}

// ExponentNode Implementation
ExponentNode::ExponentNode(Node *left, Node *right) : BinaryNode(left, right) {}

std::string ExponentNode::repr() const
{
    return "(" + left->repr() + " ** " + right->repr() + ")";
}

// UnaryNode Implementation
UnaryNode::UnaryNode(Node *node) : node(node) {}

UnaryNode::~UnaryNode()
{
    delete node;
}

Node *UnaryNode::getNode() const
{
    return node;
}

// PlusNode Implementation
PlusNode::PlusNode(Node *node) : UnaryNode(node) {}

std::string PlusNode::repr() const
{
    return "(+" + node->repr() + ")";
}

// MinusNode Implementation
MinusNode::MinusNode(Node *node) : UnaryNode(node) {}

std::string MinusNode::repr() const
{
    return "(-" + node->repr() + ")";
}
