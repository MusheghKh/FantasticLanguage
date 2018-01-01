//
// Created by max on 12/29/17.
//

#include "Parser.h"
#include "ast/UnaryExpression.h"
#include "ast/BinaryExpression.h"
#include "ast/VariableExpression.h"
#include "ast/AssignmentStatement.h"
#include "ast/PrintStatement.h"
#include "ast/ValueExpression.h"

using std::vector;
using std::string;

Parser::Parser(const std::vector<Token *>& tokensIn) : tokens(tokensIn) {
}

Parser::~Parser() {
    for (auto stat = statements.begin(); stat < statements.end(); ++stat) {
        delete *stat;
    }
    /// Tokens will delete in Lexer cause it reference to Lexer value
//    for (auto token = tokens.begin(); token < tokens.end(); ++token) {
//        delete *token;
//    }
    delete EOF_TOKEN;

    std::cout << "destruct Parser" << std::endl;
}

const std::vector<Statement *>& Parser::parse() {
    while (!match(Token::TOKEN_EOF)) {
        Statement *stat = statement();
        statements.push_back(stat);
    }
    return statements;
}

Statement *Parser::statement() {
    if (match(Token::PRINT)){
        return new PrintStatement(expression());
    }
    return assignmentStatement();
}

Statement *Parser::assignmentStatement() {
    const Token * current = get(0);
    if (match(Token::WORD) && get(0)->getType() == Token::EQ){
        const string &variable = current->getText();
        consume(Token::EQ);
        return new AssignmentStatement(variable, expression());
    }
    throw std::runtime_error("Unknown statement");
}

Expression *Parser::expression() {
    return additive();
}

Expression *Parser::additive() {
    Expression *result = multiplicative();

    while (true) {
        if (match(Token::PLUS)) {
            result = new BinaryExpression('+', result, multiplicative());
            continue;
        }
        if (match(Token::MINUS)) {
            result = new BinaryExpression('-', result, multiplicative());
            continue;
        }
        break;
    }
    return result;
}

Expression *Parser::multiplicative() {
    Expression *result = unary();

    while (true) {
        if (match(Token::STAR)) {
            result = new BinaryExpression('*', result, unary());
            continue;
        }
        if (match(Token::SLASH)) {
            result = new BinaryExpression('/', result, unary());
            continue;
        }
        break;
    }

    return result;
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
        return new ValueExpression(std::stod(current->getText()));
    }
    if (match(Token::HEX_NUMBER)) {
        return new ValueExpression(std::stol(current->getText(), nullptr, 16));
    }
    if (match(Token::WORD)){
        return new VariableExpression(current->getText());
    }
    if (match(Token::TEXT)){
        return new ValueExpression(current->getText());
    }
    if (match(Token::LPAREN)) {
        Expression *result = expression();
        match(Token::RPAREN);
        return result;
    }
    throw std::runtime_error("Unknown expression");
}

const Token *Parser::consume(Token::TokenType type) {
    const Token * current = get(0);
    if (type != current->getType()){
        throw std::runtime_error("Token " + current->toString() + " doesn't match " + Token::typeToString(type));
    }
    pos++;
    return current;
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