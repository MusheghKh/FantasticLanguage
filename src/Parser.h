//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_PARSER_H
#define OWNCPP_PARSER_H


#include <vector>
#include "Token.h"
#include "ast/Expression.h"

class Parser {
public:

    explicit Parser(const std::vector<Token*>& tokensIn);

    ~Parser();

    const std::vector<Expression*>& parse();

private:

    Expression * expression();

    Expression * additive();

    Expression * multiplicative();

    Expression * unary();

    Expression * primary();

    bool match(Token::TokenType type);

    const Token * get(unsigned long relativePosition);

    /// Constants
    const std::vector<Token*>& tokens;
    const unsigned long size = tokens.size();

    /// Variables
    std::vector<Expression*> expressions;
    unsigned long pos = 0;
};

/// Static
static const Token *EOF_TOKEN = Token::makeNew(Token::TOKEN_EOF, "");

#endif //OWNCPP_PARSER_H
