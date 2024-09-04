#include <string>
#include <vector>
#include <iostream>

// #include "TokenType.cpp"
#include "Token.cpp"
#include "TokenType.h"

class Scanner {
    private:
    std::string source;
    std::vector<Token> tokens;
    int start;
    int current;
    int line;

    public:
    Scanner() : start(0), current(0), line(0) {}

    Scanner(std::string source) {
        source = source;
    }

    std::vector<Token> scanTokens() {
        while (!isAtEnd()) {
            // We are at the beginning of the next lexeme.
            start = current;
            // scanToken();
        }

        Token token(TokenType::END_OF_FILE, "", NULL, line);
        // Token token(TokenType::END_OF_FILE, "", NULL, line);

        // tokens.add(new Token(END_OF_FILE, "", NULL, line));
        tokens.push_back(token);
        return tokens;
    }


    void getToken() {
        Token token(TokenType::END_OF_FILE, "", NULL, line);
        std::cout << token << std::endl;
    }


    private:
    bool isAtEnd() {
        return current >= source.length();
    }
};


int main() {

    Scanner scanner;

    scanner.getToken();

}