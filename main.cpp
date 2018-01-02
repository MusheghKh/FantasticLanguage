#include <iostream>

#include "include/Lexer.h"
#include "include/Parser.h"

using namespace parser;

int main() {

    string rawProgram = readFile("../program.diagram");

    Lexer lexer(rawProgram);
    const vector<const Token*> tokens = lexer.tokenize();
    cout << "********TOKENS START********" << endl;
    for (auto token = tokens.begin(); token < tokens.end(); ++token) {
        cout << (*token)->toString() << endl;
    }
    cout << "********TOKENS END********" << endl << endl;

    Parser parser(tokens);
    const BlockStatement program = parser.parse();
    cout << "********STATEMENTS START********" << endl;
    cout << program.toString() << endl;
    cout << "********STATEMENTS END********" << endl << endl;

    program.execute();

    cout << endl;

    return 0;
}