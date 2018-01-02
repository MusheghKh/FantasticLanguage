//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_TOKEN_H
#define OWNCPP_TOKEN_H

#include <string>
#include <utility>
#include <iostream>
#include <sstream>

#include "utils/common_utils.h"

using namespace utils;

namespace parser{

    class Token {
    public:

        enum TokenType {
            NUMBER,
            HEX_NUMBER,
            WORD,
            TEXT,

            /// Keyword
                    PRINT,
            IF,
            ELSE,
            WHILE,
            FOR,
            DO,
            BREAK,
            CONTINUE,

            PLUS,   /// +
            MINUS,  /// -
            STAR,   /// *
            SLASH,  /// /
            EQ,     /// =
            EQEQ,   /// ==
            EXCL,   /// !
            EXCLEQ, /// !=
            LT,     /// <
            LTEQ,   /// <=
            GT,     /// >
            GTEQ,   /// >=

            BAR,    /// |
            BARBAR, /// ||
            AMP,    /// &
            AMPAMP, /// &&

            LPAREN, /// (
            RPAREN, /// )
            LBRACE, /// {
            RBRACE, /// }
            COMMA,  /// ,

            TOKEN_EOF
        };

        ~Token() {
            std::cout << "destruct Token : " << toString() << std::endl;
        };

        static const Token *New(TokenType typeIn, const std::string &textIn) {
            return new Token(typeIn, textIn);
        }

        TokenType getType() const {
            return type;
        }

        const std::string &getText() const {
            return text;
        }

        static const std::string typeToString(TokenType);

        const std::string toString() const;

    private:
        /// Private Constructor
        Token(TokenType typeIn, std::string textIn);

        /// Constants
        const TokenType type;
        const std::string text;
    };
}

#endif //OWNCPP_TOKEN_H
