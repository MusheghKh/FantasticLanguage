#include <iostream>

#include <vector>

#include "src/ast/Expression.h"
#include "src/Lexer.h"
#include "src/Parser.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {

    const string input1 = "2 + 2";
    const string input2 = "(2 + 2) * 0xf";

    Lexer lexer(input2);
    const vector<Token*> tokens = lexer.tokenize();
    for (auto token = tokens.begin(); token < tokens.end(); ++token) {
        cout << (*token)->toString() << endl;
    }

    cout << endl;

    Parser parser(tokens);
    const vector<Expression*> expressions = parser.parse();
    for (auto expr = expressions.begin(); expr < expressions.end(); ++expr) {
        cout << (*expr)->toString() << " = " << (*expr)->eval() << endl;
    }

    cout << endl;

    return 0;
}