//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_PARSER_H
#define OWNCPP_PARSER_H


#include <vector>

#include "Token.h"
#include "../include/ast/AstNode.h"

using namespace ast;

namespace parser {

    class Parser {
    public:

        explicit Parser(const std::vector<const Token *> &tokensIn);

        ~Parser();

        const BlockStatement parse();

    private:

        const Statement *block();

        const Statement *statementOrBlock();

        const Statement *statement();

        const Statement *assignmentStatement();

        const Statement *ifElse();

        const Statement *whileStatement();

        const Statement *doWhileStatement();

        const Statement *forStatement();

        const Expression *expression();

        const Expression *logicalOr();

        const Expression *logicalAnd();

        const Expression *equality();

        const Expression *conditional();

        const Expression *additive();

        const Expression *multiplicative();

        const Expression *unary();

        const Expression *primary();

        const Token *consume(Token::TokenType type);

        bool match(Token::TokenType type);

        const Token *get(unsigned long relativePosition);

        /// Static Constant
        static const Token *EOF_TOKEN;

        /// Constants
        const std::vector<const Token *> &tokens;
        const unsigned long size = tokens.size();

        /// Variables
        unsigned long pos = 0;
    };

}

#endif //OWNCPP_PARSER_H
