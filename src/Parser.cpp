//
// Created by max on 12/29/17.
//

#include "../include/Parser.h"

using namespace parser;

const Token * Parser::EOF_TOKEN = Token::New(Token::TOKEN_EOF, "");

Parser::Parser(const vector<const Token *>& tokensIn) : tokens(tokensIn) {
}

Parser::~Parser() {
    /// Tokens will delete in Lexer cause it reference to Lexer value
    delete EOF_TOKEN;
}

const BlockStatement Parser::parse() {
    BlockStatement program;
    while (!match(Token::TOKEN_EOF)) {
        const Statement *stat = statement();
        program.add(stat);
    }
    return program;
}

const Statement *Parser::block() {
    auto *block = new BlockStatement();
    consume(Token::LBRACE);
    while (!match(Token::RBRACE)){
        block->add(statement());
    }
    return block;
}

const Statement *Parser::statementOrBlock() {
    if (get(0)->getType() == Token::LBRACE){
        return block();
    }
    return statement();
}

const Statement *Parser::statement() {
    if (match(Token::PRINT)){
        return new PrintStatement(expression());
    }
    if (match(Token::IF)){
        return ifElse();
    }
    if (match(Token::WHILE)){
        return whileStatement();
    }
    if (match(Token::FOR)){
        return forStatement();
    }
    if (match(Token::DO)){
        return doWhileStatement();
    }
    if (match(Token::BREAK)){
        return new BreakStatement();
    }
    if (match(Token::CONTINUE)){
        return new ContinueStatement();
    }
    return assignmentStatement();
}

const Statement *Parser::assignmentStatement() {
    const Token * current = get(0);
    if (match(Token::WORD) && get(0)->getType() == Token::EQ){
        const string &variable = current->getText();
        consume(Token::EQ);
        return new AssignmentStatement(variable, expression());
    }
    throw runtime_error("Unknown statement");
}

const Statement *Parser::ifElse() {
    const Expression* condition = expression();
    const Statement* ifStatement = statementOrBlock();

    if (match(Token::ELSE)){
        return new IfStatement(condition, ifStatement, statementOrBlock());
    }
    return new IfStatement(condition, ifStatement);
}

const Statement *Parser::whileStatement() {
    const Expression *condition = expression();
    const Statement *body = statementOrBlock();
    return new WhileStatement(condition, body);
}

const Statement *Parser::doWhileStatement() {
    const Statement *statement = statementOrBlock();
    consume(Token::WHILE);
    const Expression *condition = expression();
    return new DoWhileStatement(condition, statement);
}

const Statement *Parser::forStatement() {
    const Statement *initialization = assignmentStatement();
    consume(Token::COMMA);
    const Expression *termination = expression();
    consume(Token::COMMA);
    const Statement *increment = assignmentStatement();
    const Statement *body = statementOrBlock();
    return new ForStatement(initialization, termination, increment, body);
}


const Expression *Parser::expression() {
    return logicalOr();
}

const Expression *Parser::logicalOr() {
    const Expression *result = logicalAnd();

    while (true){
        if (match(Token::BARBAR)){
            result = new ConditionalExpression(ConditionalExpression::OR, result, logicalAnd());
            continue;
        }
        break;
    }
    return result;
}

const Expression *Parser::logicalAnd() {
    const Expression *result = equality();

    while (true){
        if (match(Token::AMPAMP)){
            result = new ConditionalExpression(ConditionalExpression::AND, result, equality());
            continue;
        }
        break;
    }

    return result;
}

const Expression *Parser::equality() {
    const Expression *result = conditional();

    if (match(Token::EQEQ)){
        return new ConditionalExpression(ConditionalExpression::EQUALS, result, conditional());
    }
    if (match(Token::EXCLEQ)){
        return new ConditionalExpression(ConditionalExpression::NOT_EQUALS, result, conditional());
    }

    return result;
}

const Expression *Parser::conditional() {
    const Expression *result = additive();

    while (true){
        if (match(Token::LT)){
            result = new ConditionalExpression(ConditionalExpression::LT, result, additive());
            continue;
        }
        if (match(Token::LTEQ)){
            result = new ConditionalExpression(ConditionalExpression::LTEQ, result, additive());
            continue;
        }
        if (match(Token::GT)){
            result = new ConditionalExpression(ConditionalExpression::GT, result, additive());
            continue;
        }
        if (match(Token::GTEQ)){
            result = new ConditionalExpression(ConditionalExpression::GTEQ, result, additive());
            continue;
        }
        break;
    }

    return result;
}

const Expression *Parser::additive() {
    const Expression *result = multiplicative();

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

const Expression *Parser::multiplicative() {
    const Expression *result = unary();

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

const Expression *Parser::unary() {
    if (match(Token::MINUS)) {
        return new UnaryExpression('-', primary());
    }
    if (match(Token::PLUS)) {
        return primary();
    }
    return primary();
}


const Expression *Parser::primary() {
    const Token *current = get(0);
    if (match(Token::NUMBER)) {
        return new ValueExpression(stod(current->getText()));
    }
    if (match(Token::HEX_NUMBER)) {
        return new ValueExpression(stol(current->getText(), nullptr, 16));
    }
    if (match(Token::WORD)){
        return new VariableExpression(current->getText());
    }
    if (match(Token::TEXT)){
        return new ValueExpression(current->getText());
    }
    if (match(Token::LPAREN)) {
        const Expression *result = expression();
        match(Token::RPAREN);
        return result;
    }
    throw runtime_error("Unknown expression");
}

const Token *Parser::consume(Token::TokenType type) {
    const Token * current = get(0);
    if (type != current->getType()){
        throw runtime_error("Token " + current->toString() + " doesn't match " + Token::typeToString(type));
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
