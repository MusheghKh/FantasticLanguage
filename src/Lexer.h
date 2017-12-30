//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_LEXER_H
#define OWNCPP_LEXER_H

#include "Token.h"

#include <string>
#include <utility>
#include <vector>

class Lexer {
public:

    explicit Lexer(const std::string& inputIn);

    ~Lexer();

    std::vector<Token*> & tokenize();
private:

    void tokenizeNumber();

    void tokenizeHexNumber();

    void tokenizeOperator();

    void step(unsigned long step);

    char next();

    char peek(unsigned long relativePosition);

    void addToken(Token::TokenType type){
        addToken(type, "");
    }

    void addToken(Token::TokenType type, const std::string &text){
        tokens.push_back(Token::makeNew(type, text));
    }

    /// Static method
    static bool isHexNumber(char current);

    /// Constants
    const std::string input;
    const unsigned long length = input.length();

    /// Variables
    std::vector<Token*> tokens;
    unsigned long pos = 0;
};

/// Static
static const std::string OPERATOR_CHARS = "+-*/()";
static const Token::TokenType OPERATOR_TOKENS[6] = {
        Token::PLUS, Token::MINUS,
        Token::STAR, Token::SLASH,
        Token::LPAREN, Token::RPAREN
};

#endif //OWNCPP_LEXER_H
