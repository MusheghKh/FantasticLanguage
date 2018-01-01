#include <iostream>

#include <vector>

#include "src/common_utils.h"
#include "src/Lexer.h"
#include "src/Parser.h"
#include "src/lib/Variables.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {

    string rawProgram = readFile("../program.diagram");

    Lexer lexer(rawProgram);
    const vector<Token*> tokens = lexer.tokenize();
    cout << "********TOKENS START********" << endl;
    for (auto token = tokens.begin(); token < tokens.end(); ++token) {
        cout << (*token)->toString() << endl;
    }
    cout << "********TOKENS END********" << endl << endl;

    Parser parser(tokens);
    const vector<Statement*> statements = parser.parse();
    cout << "********STATEMENTS START********" << endl;
    for (auto stat = statements.begin(); stat < statements.end(); ++stat) {
        cout << (*stat)->toString() << endl;
    }
    cout << "********STATEMENTS END********" << endl << endl;

    for (auto stat = statements.begin(); stat < statements.end(); ++stat) {
        (*stat)->execute();
    }

    cout << endl;

    return 0;
}