//
// Created by max on 12/29/17.
//

#include "Parser.h"
#include "ast/NumberExpression.h"
#include "ast/UnaryExpression.h"
#include "ast/BinaryExpression.h"
#include "ast/ConstantExpression.h"

using std::vector;

Parser::Parser(const std::vector<Token *>& tokensIn) : tokens(tokensIn) {
}

Parser::~Parser() {
    for (auto expr = expressions.begin(); expr < expressions.end(); ++expr) {
        delete *expr;
    }
    for (auto token = tokens.begin(); token < tokens.end(); ++token) {
        delete *token;
    }
    delete EOF_TOKEN;

    std::cout << "destruct Parser" << std::endl;
}

const std::vector<Expression *>& Parser::parse() {
    while (!match(Token::TOKEN_EOF)) {
        Expression *expr = expression();
        expressions.push_back(expr);
    }
    return expressions;
}

Expression *Parser::expression() {
    return additive();
}

Expression *Parser::additive() {
    Expression *result = nullptr;
    Expression *mult = multiplicative();

    while (true) {
        if (match(Token::PLUS)) {
            result = new BinaryExpression('+', mult, multiplicative());
            continue;
        }
        if (match(Token::MINUS)) {
            result = new BinaryExpression('-', mult, multiplicative());
            continue;
        }
        break;
    }
    if (result) {
        return result;
    }
    return mult;
}

Expression *Parser::multiplicative() {
    Expression *result = nullptr;
    Expression *un = unary();

    while (true) {
        if (match(Token::STAR)) {
            result = new BinaryExpression('*', un, unary());
            continue;
        }
        if (match(Token::SLASH)) {
            result = new BinaryExpression('/', un, unary());
            continue;
        }
        break;
    }

    if (result) {
        return result;
    }
    return un;
}

Expression *Parser::unary() {
    if (match(Token::MINUS)) {
        return new UnaryExpression('-', primary());
    }
    if (match(Token::PLUS)) {
        return primary();
    }
    return primary();
}


Expression *Parser::primary() {
    const Token *current = get(0);
    if (match(Token::NUMBER)) {
        return new NumberExpression(std::stod(current->getText()));
    }
    if (match(Token::HEX_NUMBER)) {
        return new NumberExpression(std::stol(current->getText(), nullptr, 16));
    }
    if (match(Token::WORD)){
        return new ConstantExpression(current->getText());
    }
    if (match(Token::LPAREN)) {
        Expression *result = expression();
        match(Token::RPAREN);
        return result;
    }
    throw std::runtime_error("Unknown expression");
}

bool Parser::match(Token::TokenType type) {
    const Token *current = get(0);
    if (type != current->getType()) {
        return false;
    }
    pos++;
    return true;
}

const Token *Parser::get(unsigned long relativePosition) {
    unsigned long position = pos + relativePosition;
    if (position >= size) {
        return EOF_TOKEN;
    }
    return tokens[position];
}