#include "interpreter.h"
#include "nodes.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

// Evaluates the AST
double Interpreter::visit(Node *node)
{
    if (auto numberNode = dynamic_cast<NumberNode *>(node))
        return visitNumber(numberNode);
    if (auto addNode = dynamic_cast<AddNode *>(node))
        return visitAdd(addNode);
    if (auto subtractNode = dynamic_cast<SubtractNode *>(node))
        return visitSubtract(subtractNode);
    if (auto multiplyNode = dynamic_cast<MultiplyNode *>(node))
        return visitMultiply(multiplyNode);
    if (auto divideNode = dynamic_cast<DivideNode *>(node))
        return visitDivide(divideNode);
    if (auto modulusNode = dynamic_cast<ModulusNode *>(node))
        return visitModulus(modulusNode);
    if (auto exponentNode = dynamic_cast<ExponentNode *>(node))
        return visitExponent(exponentNode);
    if (auto plusNode = dynamic_cast<PlusNode *>(node))
        return visitPlus(plusNode);
    if (auto minusNode = dynamic_cast<MinusNode *>(node))
        return visitMinus(minusNode);

    throw ErrorHandling("Unknown node type");
}

// Visit methods for specific node types
double Interpreter::visitNumber(NumberNode *node)
{
    return node->getValue();
}

double Interpreter::visitAdd(AddNode *node)
{
    return visit(node->getLeft()) + visit(node->getRight());
}

double Interpreter::visitSubtract(SubtractNode *node)
{
    return visit(node->getLeft()) - visit(node->getRight());
}

double Interpreter::visitMultiply(MultiplyNode *node)
{
    return visit(node->getLeft()) * visit(node->getRight());
}

double Interpreter::visitDivide(DivideNode *node)
{
    double right = visit(node->getRight());
    if (right == 0) 
        throw ErrorHandling("Divison by zero");

    return visit(node->getLeft()) / right;
}

double Interpreter::visitModulus(ModulusNode *node)
{
    int left = static_cast<int>(visit(node->getLeft()));
    int right = static_cast<int>(visit(node->getRight()));
    if (right == 0)
        throw ErrorHandling("Modulus by zero");
    return left % right;
}

double Interpreter::visitExponent(ExponentNode *node)
{
    return std::pow(visit(node->getLeft()), visit(node->getRight()));
}

double Interpreter::visitPlus(PlusNode *node)
{
    return visit(node->getNode());
}

double Interpreter::visitMinus(MinusNode *node)
{
    return -visit(node->getNode());
}
