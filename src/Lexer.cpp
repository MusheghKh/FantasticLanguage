//
// Created by max on 12/29/17.
//

#include "Lexer.h"

#include <sstream>

using std::string;
using std::stringstream;

Lexer::Lexer(const std::string& inputIn) : input(inputIn) {
}

Lexer::~Lexer() {
//    for (auto i = tokens.begin(); i < tokens.end(); ++i) {
//        delete *i;
//    }
    std::cout << "destruct Lexer" << std::endl;
}

std::vector<Token *> &Lexer::tokenize() {
    while (pos < length) {
        const char current = peek(0);
        if (isdigit(current)) {
            if (current == '0' && peek(1) == 'x') {
                step(2);
                tokenizeHexNumber();
            } else {
                tokenizeNumber();
            }
        }
        else if (OPERATOR_CHARS.find(current) != -1) {
            tokenizeOperator();
        } else {
            // whitespaces
            step(1);
        }
    }
    return tokens;
}

void Lexer::tokenizeNumber() {
    stringstream ss;
    char current = peek(0);
    while (isdigit(current)) {
        ss << current;
        current = next();
    }
    addToken(Token::NUMBER, ss.str());
}

void Lexer::tokenizeHexNumber() {
    stringstream ss;
    char current = peek(0);
    while (isHexNumber(current)) {
        ss << current;
        current = next();
    }
    addToken(Token::HEX_NUMBER, ss.str());
}


bool Lexer::isHexNumber(char current) {
    string chars = "abcdef";
    return isdigit(current) || chars.find(current) != -1;
}


void Lexer::tokenizeOperator() {
    unsigned long position = OPERATOR_CHARS.find(peek(0));
    addToken(OPERATOR_TOKENS[position]);
    step(1);
}

void Lexer::step(unsigned long step) {
    pos += step;
}

char Lexer::next() {
    pos++;
    return peek(0);
}

char Lexer::peek(unsigned long relativePosition) {
    unsigned long position = pos + relativePosition;
    if (position >= length) {
        return '\0';
    }
    return input.at(position);
}