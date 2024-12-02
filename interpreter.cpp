#include <iostream>
#include <stdexcept>
#include <cmath>
#include "nodes.cpp"  //from the nodes.cpp file

class Interpreter {
public:
    // Retrieves the value stored in a NumberNode.
    double visit(NumberNode* node) {
        return node->getValue();
    }

    // Computes the sum of the left and right operands
    double visit(AddNode* node) {
        return visit(node->getLeft()) + visit(node->getRight());
    }

    // Computes the difference between the left and right operands 
    double visit(SubtractNode* node) {
        return visit(node->getLeft()) - visit(node->getRight());
    }

    // Computes the product of the left and right operands 
    double visit(MultiplyNode* node) {
        return visit(node->getLeft()) * visit(node->getRight());
    }

    // Computes the quotient of the left and right operands 
    double visit(DivideNode* node) {
        double rightValue = visit(node->getRight());
        if (rightValue == 0.0) { // Throws an exception if you try to divide by 0
            throw std::runtime_error("Division by zero");
        }
        return visit(node->getLeft()) / rightValue;
    }

    // Computes the remainder of the division of the left operand by the right operand 
    double visit(ModulusNode* node) {
        double leftValue = visit(node->getLeft());
        double rightValue = visit(node->getRight());
        if (rightValue == 0.0) {
            throw std::runtime_error("Modulus by zero");
        }
        return std::fmod(leftValue, rightValue);
    }

    // Computes the result of raising the left operand to the power of the right operand in an ExponentNode.
    double visit(ExponentNode* node) {
        return std::pow(visit(node->getLeft()), visit(node->getRight()));
    }

    // Returns the value of the node
    double visit(PlusNode* node) {
        return visit(node->getNode());
    }

    // Returns the negated value of the node
    double visit(MinusNode* node) {
        return -visit(node->getNode());
    }
};