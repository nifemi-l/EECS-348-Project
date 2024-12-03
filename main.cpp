#include <iostream>
#include <vector>
#include <string>
#include "tokens.h"
#include "nodes.h"
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

int main()
{
	try
	{
		// Prompt the user to enter an expression
		std::cout << "Enter a mathematical expression: ";
		std::string input;
		std::getline(std::cin, input);

		// Step 1: Lexical Analysis (Tokenization)
		Lexer lexer(input);
		std::vector<Token> tokens = lexer.generateTokens();

		std::cout << "\nTokens:" << std::endl;
		for (const Token &token : tokens)
		{
			std::cout << token.toString() << std::endl;
		}

		// Step 2: Parsing (Build AST)
		Parser parser(tokens);
		Node *ast = parser.parse();

		// Step 3: Print the AST representation
		std::cout << "\nAbstract Syntax Tree:" << std::endl;
		std::cout << ast->repr() << std::endl;

		// Step 4: Interpret the AST
		Interpreter interpreter;
		double result = interpreter.visit(ast);

		std::cout << "\nResult: " << result << std::endl;

		// Clean up the AST
		delete ast;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
