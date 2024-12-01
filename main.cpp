/*Daniel Van Dalsem*/
#include <stdio.h>
#include <string>
#include <vector>
#include "lexer.cpp"
#include "parser.cpp"
#include "interpreter.cpp"
#include "errorhandling.h"
using namespace std;
//import lexer, parser, interpreter

int main(){
while (true) {
	try {
		string text = "";
		cout << "> ";
		cin >> text;
		Lexer lexer = Lexer(text);
		vector<Token> tokens = lexer.generateTokens();
		Parser parser = Parser(tokens);
		//I am not sure what type this will be???
		vector<Token> tree = Parser.parse();
		// I don't think you can return null in c++ in this case so
		if (false){
			continue;
		}
		Interpreter interpreter = Interpreter();
		// I also don't know what type this will be
		float value = Interpreter.visit(tree);
		cout<<value<<endl;
	}
	catch (const std::exception& e) {
	cout<<e.what();
	}
}
}
