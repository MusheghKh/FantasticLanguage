#include <iostream>

#include <vector>

#include "src/ast/Expression.h"
#include "src/Lexer.h"
#include "src/Parser.h"
#include "src/lib/Variables.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {

    const string input1 = "2 + 2";
    const string input2 = "(PI + 2) * 0xf";
    const string input3 = "v1 = 2 + 2 \n v2 = PI + v1";

    Lexer lexer(input3);
    const vector<Token*> tokens = lexer.tokenize();
    for (auto token = tokens.begin(); token < tokens.end(); ++token) {
        cout << (*token)->toString() << endl;
    }

    cout << endl;

    Parser parser(tokens);
    const vector<Statement*> statements = parser.parse();
    for (auto stat = statements.begin(); stat < statements.end(); ++stat) {
        cout << (*stat)->toString() << endl;
    }
    for (auto stat = statements.begin(); stat < statements.end(); ++stat) {
        (*stat)->execute();
    }

    cout << endl;

    return 0;
}