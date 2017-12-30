//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_TOKEN_H
#define OWNCPP_TOKEN_H

#include <string>
#include <utility>
#include <iostream>

class Token {
public:

    enum TokenType{
        NUMBER,
        HEX_NUMBER,

        PLUS,   /// +
        MINUS,  /// -
        STAR,   /// *
        SLASH,  /// /

        LPAREN, /// (
        RPAREN, /// )

        TOKEN_EOF
    };

    ~Token(){
        std::cout << "destruct Token : " << toString() << std::endl;
    };

    static Token* makeNew(TokenType typeIn, const std::string& textIn){
        return new Token(typeIn, textIn);
    }

    TokenType getType() const {
        return type;
    }

    const std::string & getText() const {
        return text;
    }

    const std::string toString();

private:
    /// Private Constructor
    Token(TokenType typeIn, const std::string& textIn);

    /// Constants
    const TokenType type;
    const std::string text;
};

#endif //OWNCPP_TOKEN_H
