//
// Created by max on 12/29/17.
//

#include "../include/Lexer.h"

using namespace parser;
/**
 * Initialize static const memebers
 * */
const string Lexer::OPERATOR_CHARS = "+-*/(){}=<>!&|,";
const map<std::string, Token::TokenType> Lexer::OPERATORS  = {
        {"+", Token::PLUS},
        {"-", Token::MINUS},
        {"*", Token::STAR},
        {"/", Token::SLASH},
        {"(", Token::LPAREN},
        {")", Token::RPAREN},
        {"{", Token::LBRACE},
        {"}", Token::RBRACE},
        {"=", Token::EQ},
        {"<", Token::LT},
        {">", Token::GT},
        {",", Token::COMMA},

        {"!", Token::EXCL},
        {"&", Token::AMP},
        {"|", Token::BAR},

        {"==", Token::EQEQ},
        {"!=", Token::EXCLEQ},
        {"<=", Token::LTEQ},
        {">=", Token::GTEQ},

        {"&&", Token::AMPAMP},
        {"||", Token::BARBAR}
};

Lexer::Lexer(string inputIn) : input(move(inputIn)) {
}

Lexer::~Lexer() {
    for (auto token = tokens.begin(); token < tokens.end(); ++token) {
        delete *token;
    }
}

const vector<const Token *> &Lexer::tokenize() {
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
                throw runtime_error("Invalid float number");
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
    } else if(word == "while"){
        addToken(Token::WHILE);
    } else if(word == "for"){
        addToken(Token::FOR);
    } else if(word =="do"){
        addToken(Token::DO);
    } else if(word =="break"){
        addToken(Token::BREAK);
    } else if(word =="continue"){
        addToken(Token::CONTINUE);
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
            throw runtime_error("Missing close tag");
        }
        if (current == '*' && peek(1) == '/'){
            break;
        }
        current = next();
    }
    step(2);
}

void Lexer::tokenizeText() {
    step(1);
    stringstream ss;
    char current = peek(0);
    while (true) {
        if (current == '\\') {
            current = next();
            switch (current) {
                case '"':
                    current = next();
                    ss << '"';
                    continue;
                case 'n':
                    current = next();
                    ss << '\n';
                    continue;
                case 't':
                    current = next();
                    ss << '\t';
                    continue;
            }
            ss << '\\';
            continue;
        }
        if (current == '"') {
            break;
        }
        ss << current;
        current = next();
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
