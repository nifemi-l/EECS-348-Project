#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//create classes for NumberNode, add, subtract, multiply, divide, 
//modulus, exponent, plus (positive value), and minus (negative value)

class NumberNode{
    private:
    double value;

    public:
    NumberNode (double value) : value(value) {}

    std::string repr() const{
        return std::to_string(value);
    }
};

class AddNode{
    private:
    NumberNode* left;  // pointer to left operand
    NumberNode* right; // pointer to right operand

    public:
    AddNode(NumberNode* left, NumberNode* right) : left(left), right(right) {}

    std::string repr() const {
        return "(" + left->repr() + "+" + right->repr() + ")"; //-> is used to access members of a class through a pointer
    }
};

class SubtractNode{
    private:
    NumberNode* left;  // pointer to left operand
    NumberNode* right; // pointer to right operand

    public:
    SubtractNode(NumberNode* left, NumberNode* right) : left(left), right(right) {}

    std::string repr() const{
        return "(" + left -> repr() + "-" + right -> repr() + ")";
    }
};

class MultiplyNode{
    private:
    NumberNode* left;  // pointer to left operand
    NumberNode* right; // pointer to right operand

    public:
    MultiplyNode(NumberNode* left, NumberNode* right) : left(left), right(right) {}

    std::string repr() const{
        return "(" + left -> repr() + "*" + right -> repr() + ")";
    }
};

class DivideNode{
    private:
    NumberNode* left;  // pointer to left operand
    NumberNode* right; // pointer to right operand

    public:
    DivideNode(NumberNode* left, NumberNode* right) : left(left), right(right) {}

    std::string repr() const{
        return "(" + left -> repr() + "/" + right -> repr() + ")";
    }
};

class ModulusNode{
    private:
    NumberNode* left;  // pointer to left operand
    NumberNode* right; // pointer to right operand

    public:
    ModulusNode(NumberNode* left, NumberNode* right) : left(left), right(right) {}

    std::string repr() const{
        return "(" + left -> repr() + "%" + right -> repr() + ")";
    }
};

class ExponentNode{
    private:
    NumberNode* left;  // pointer to left operand
    NumberNode* right; // pointer to right operand

    public:
    ExponentNode(NumberNode* left, NumberNode* right) : left(left), right(right) {}

    std::string repr() const{
        return "(" + left -> repr() + "**" + right -> repr() + ")";
    }
};

class PlusNode {
public:
    NumberNode* node;

    PlusNode(NumberNode* node) : node(node) {}

    std::string repr() const {
        return "(+" + node->repr() + ")";
    }
};

class MinusNode {
public:
    NumberNode* node;

    MinusNode(NumberNode* node) : node(node) {}

    std::string repr() const {
        return "(-" + node->repr() + ")";
    }
};
