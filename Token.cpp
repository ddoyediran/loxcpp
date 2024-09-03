#include <string>
#include <ostream>
#include "TokenType.cpp"


class Token {
    private:
    const TokenType type;
    const std::string lexeme;
    const std::string literal;
    const int line;

    public:
    Token(TokenType type, const std::string& lexeme, const std::string& literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line) {}

    // std::string toString() {
    //     return type + " " + lexeme + " " + literal;
    // }

    friend std::ostream& operator<< (std::ostream& os, const Token& token) {
        os << static_cast<int>(token.type) << " " << token.lexeme << " " << token.literal;
        return os;
    }

};