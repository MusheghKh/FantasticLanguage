//
// Created by max on 12/29/17.
//

#include "Token.h"

#include "sstream"

using std::stringstream;

Token::Token(Token::TokenType typeIn, const std::string& textIn) : text(textIn), type(typeIn){

}

const std::string Token::typeToString(TokenType typeIn) {
    switch (typeIn){
        case NUMBER: return  "NUMBER";
        case HEX_NUMBER: return  "HEX_NUMBER";
        case WORD: return "WORD";
        case PLUS: return  "PLUS";
        case MINUS: return "MINUS";
        case STAR: return "STAR";
        case SLASH: return "SLASH";
        case EQ: return "EQ";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case TOKEN_EOF: return "EOF";
    }
}

const std::string Token::toString() const {
    stringstream ss;
    switch (type){
        case NUMBER: ss << "NUMBER "; break;
        case HEX_NUMBER: ss << "HEX_NUMBER 0x"; break;
        case WORD: ss << "WORD "; break;
        case PLUS: ss << "PLUS "; break;
        case MINUS: ss << "MINUS "; break;
        case STAR: ss << "STAR "; break;
        case SLASH: ss << "SLASH "; break;
        case EQ: ss << "EQ "; break;
        case LPAREN: ss << "LPAREN "; break;
        case RPAREN: ss << "RPAREN "; break;
        case TOKEN_EOF: ss << "EOF "; break;
        default:
            ss << "UNKNOWN_TOKEN";
    }
    ss << text;

    return ss.str();
}