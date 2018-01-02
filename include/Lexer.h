//
// Created by max on 12/29/17.
//

#ifndef OWNCPP_LEXER_H
#define OWNCPP_LEXER_H

#include "Token.h"

#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

namespace parser
{
    class Lexer {
    public:

        explicit Lexer(std::string inputIn);

        ~Lexer();

        const std::vector<const Token*> & tokenize();
    private:

        void tokenizeNumber();

        void tokenizeHexNumber();

        void tokenizeOperator();

        void tokenizeWord();

        void tokenizeText();

        void tokenizeComment();

        void tokenizeMultilineComment();

        void step(unsigned long step);

        char next();

        char peek(unsigned long relativePosition);

        void addToken(Token::TokenType type){
            addToken(type, "");
        }

        void addToken(Token::TokenType type, const std::string &text){
            tokens.push_back(Token::New(type, text));
        }

        /// Static method
        static bool isHexNumber(char current);

        /// Static Constants
        static const std::string OPERATOR_CHARS;
        static const std::map<std::string, Token::TokenType> OPERATORS;

        /// Constants
        const std::string input;
        const unsigned long length = input.length();

        /// Variables
        std::vector<const Token*> tokens;
        unsigned long pos = 0;
    };

}

#endif //OWNCPP_LEXER_H
