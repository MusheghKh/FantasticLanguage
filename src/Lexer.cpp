//
// Created by max on 12/29/17.
//

#include "Lexer.h"

#include <sstream>

using std::string;
using std::stringstream;

Lexer::Lexer(std::string inputIn) : input(std::move(inputIn)) {
}

Lexer::~Lexer() {
    for (auto token = tokens.begin(); token < tokens.end(); ++token) {
        delete *token;
    }
    std::cout << "destruct Lexer" << std::endl;
}

const std::vector<Token *> &Lexer::tokenize() {
    while (pos < length) {
        const char current = peek(0);
        if (isdigit(current)) {
            if (current == '0' && peek(1) == 'x') {
                step(2);
                tokenizeHexNumber();
            } else {
                tokenizeNumber();
            }
        } else if (isalpha(current)) {
            tokenizeWord();
        } else if (current == '"') {
            tokenizeText();
        } else if (OPERATOR_CHARS.find(current) != -1) {
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
    while (true) {
        if (current == '.') {
            // TODO make something normal than .str()
            if (ss.str().find('.') != -1) {
                throw std::runtime_error("Invalid float number");
            }
        } else if (!isdigit(current)) {
            break;
        }
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
    char current = peek(0);
    if (current == '/') {
        if (peek(1) == '/') {
            step(2);
            tokenizeComment();
            return;
        } else if (peek(1) == '*') {
            step(2);
            tokenizeMultilineComment();
            return;
        }
    }
    stringstream ss;
    while (true) {
        const string &text = ss.str();
        if (OPERATORS.find(text + current) == OPERATORS.end() && !text.empty()) {
            addToken(OPERATORS.at(text));
            return;
        }
        ss << current;
        current = next();
    }
}

void Lexer::tokenizeWord() {
    stringstream ss;
    char current = peek(0);
    while (true) {
        if (!(isdigit(current) || isalpha(current)) && current != '_' && current != '$') {
            break;
        }
        ss << current;
        current = next();
    }

    const string word = ss.str();
    if (word == "print") {
        addToken(Token::PRINT);
    } else if (word == "if") {
        addToken(Token::IF);
    } else if (word == "else") {
        addToken(Token::ELSE);
    } else {
        addToken(Token::WORD, word);
    }
}


void Lexer::tokenizeComment() {
    char current = peek(0);
    string end = "\r\n\0";
    while (end.find(current) == string::npos) {
        current = next();
    }
}

void Lexer::tokenizeMultilineComment() {
    char current = peek(0);
    while (true){
        if (current == '\0'){
            throw std::runtime_error("Missing close tag");
        }
        if (current == '*' && peek(1) == '/'){
            break;
        }
    }
    step(2);
}

void Lexer::tokenizeText() {
    step(1);
    stringstream ss;
    char currnet = peek(0);
    while (true) {
        if (currnet == '\\') {
            currnet = next();
            switch (currnet) {
                case '"':
                    currnet = next();
                    ss << '"';
                    continue;
                case 'n':
                    currnet = next();
                    ss << '\n';
                    continue;
                case 't':
                    currnet = next();
                    ss << '\t';
                    continue;
            }
            ss << '\\';
            continue;
        }
        if (currnet == '"') {
            break;
        }
        ss << currnet;
        currnet = next();
    }
    next();

    addToken(Token::TEXT, ss.str());
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
