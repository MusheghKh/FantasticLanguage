//
// Created by max on 12/29/17.
//

#include "Token.h"

#include "common_utils.h"

#include "sstream"

using std::stringstream;

Token::Token(Token::TokenType typeIn, std::string textIn)
        : text(std::move(textIn)), type(typeIn){

}

const std::string Token::typeToString(TokenType typeIn) {
    switch (typeIn){
        case NUMBER: return  "NUMBER";
        case HEX_NUMBER: return  "HEX_NUMBER";
        case WORD: return "WORD";
        case TEXT: return "TEXT";
        case PRINT: return "PRINT";
        case IF: return "IF";
        case ELSE: return "ELSE";
        case WHILE: return "WHILE";
        case FOR: return "FOR";
        case DO: return "DO";
        case BREAK: return "BREAK";
        case CONTINUE: return "CONTINUE";
        case PLUS: return  "PLUS";
        case MINUS: return "MINUS";
        case STAR: return "STAR";
        case SLASH: return "SLASH";
        case EQ: return "EQ";
        case EQEQ: return "EQEQ";
        case EXCL: return "EXCL";
        case EXCLEQ: return "EXQLEQ";
        case LT: return "LT";
        case LTEQ: return "LTEQ";
        case GT: return "GT";
        case GTEQ: return "GTEQ";
        case BAR: return "BAR";
        case BARBAR: return "BARBAR";
        case AMP: return "AMP";
        case AMPAMP: return "AMPAMP";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case LBRACE: return "LBRACE";
        case RBRACE: return "RBRACE";
        case COMMA: return "COMMA";
        case TOKEN_EOF: return "EOF";
        default:
            return  "UNKNOWN_TOKEN";
    }
}

const std::string Token::toString() const {
    stringstream ss;
    ss << typeToString(type) << ' ';
    if (type == HEX_NUMBER){
        ss << "0x";
    }
    ss << text;

    return makeRawSpecialChars(ss.str());
}