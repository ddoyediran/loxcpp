#include <string>
#include "TokenType.cpp"


class Token {
    private:
    const TokenType type;
    const std::string lexeme;
    const std::string literal;
    const int line;

    public:
    Token(TokenType type, std::string lexeme, std::string literal, int line) {
        type = type;
        lexeme = lexeme;
        literal = literal;
        line = line;
    }

    std::string toString() {
        return type + " " + lexeme + " " + literal;
    }


};