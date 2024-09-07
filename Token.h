#include <string>
#include <ostream>

#include "TokenType.h"


class Token {
    private:
    const TokenType type;
    const std::string lexeme;
    const std::string literal;
    const int line;

    public:
    Token(TokenType type, const std::string& lexeme, const std::string& literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line) {}

    std::string toString() const {
        return std::to_string(static_cast<int>(type)) + " " + lexeme + " " + literal;
    }

    // std::string toString() const {
    //     return std::to_string(static_cast<int>(type)) + " " + lexeme + (literal ? " " + *literal : "");
    // }

    // std::string toString() const {
    //     return std::to_string(static_cast<int>(type)) + " " + lexeme + (literal != nullptr ? " " + *literal : "");
    // }

    friend std::ostream& operator<< (std::ostream& os, const Token& token) {
        os << static_cast<int>(token.type) << " " << token.lexeme << " " << token.literal;
        return os;
    }

};