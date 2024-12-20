#include "interpreter.h"
#include "lexer.h"
#include "nodes.h"
#include "parser.h"
#include "tokens.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  try {
    while (true) {
      // Prompt the user to enter an expression
      std::cout << "Enter a mathematical expression, input stop to end: ";
      std::string input;

      std::getline(std::cin, input);
      if (input == "stop") {
        break;
      }
      // Step 1: Lexical Analysis (Tokenization)
      Lexer lexer(input);
      std::vector<Token> tokens = lexer.generateTokens();

      // Step 2: Parsing (Build AST)
      Parser parser(tokens);
      Node *ast = parser.parse();

      // Step 3: Print the AST representation

      // Step 4: Interpret the AST
      Interpreter interpreter;
      double result = interpreter.visit(ast);

      std::cout << "\nResult: " << result << std::endl;

      // Clean up the AST
      delete ast;
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
