#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "nodes.h"

class Interpreter
{
public:
    // Evaluates a node and returns its computed value
    double visit(Node *node);

private:
    // Visit methods for each node type
    double visitNumber(NumberNode *node);
    double visitAdd(AddNode *node);
    double visitSubtract(SubtractNode *node);
    double visitMultiply(MultiplyNode *node);
    double visitDivide(DivideNode *node);
    double visitModulus(ModulusNode *node);
    double visitExponent(ExponentNode *node);
    double visitPlus(PlusNode *node);
    double visitMinus(MinusNode *node);
};

#endif // INTERPRETER_H
