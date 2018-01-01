//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_PARSER_H
#define OWNCPP_PARSER_H


#include <vector>
#include "Token.h"
#include "ast/Expression.h"
#include "ast/Statement.h"

class Parser {
public:

    explicit Parser(const std::vector<Token*>& tokensIn);

    ~Parser();

    const std::vector<Statement*>& parse();

private:

    Statement* statement();

    Statement* assignmentStatement();

    Statement* ifElse();

    Expression * expression();

    Expression * logicalOr();

    Expression * logicalAnd();

    Expression * equality();

    Expression * conditional();

    Expression * additive();

    Expression * multiplicative();

    Expression * unary();

    Expression * primary();

    const Token * consume(Token::TokenType type);

    bool match(Token::TokenType type);

    const Token * get(unsigned long relativePosition);

    /// Constants
    const std::vector<Token*>& tokens;
    const unsigned long size = tokens.size();

    /// Variables
    std::vector<Statement*> statements;
    unsigned long pos = 0;
};

/// Static
static const Token *EOF_TOKEN = Token::New(Token::TOKEN_EOF, "");

#endif //OWNCPP_PARSER_H
