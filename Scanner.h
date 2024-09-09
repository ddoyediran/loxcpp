#include <string>
#include <vector>
#include <iostream>

#include "Token.h"
//#include "TokenType.h"
#include "Error.h"

class Scanner {
    private:
    std::string source;
    std::vector<Token> tokens;
    int start;
    int current;
    int line;

    public:
    // Scanner() : start(0), current(0), line(0) {}

    Scanner(std::string source) : start(0), current(0), line(1) {
        source = source;
    }

    std::vector<Token> scanTokens() {
        while (!isAtEnd()) {
            // We are at the beginning of the next lexeme.
            start = current;
            scanToken();
        }

        // Token token(TokenType::END_OF_FILE, "", NULL, line);
        // tokens.push_back(token);

        tokens.push_back(Token(TokenType::END_OF_FILE, "", "", line));
        // tokens.push_back(Token(TokenType::END_OF_FILE, "", nullptr, line));
        return tokens;
    }


    private:
    bool isAtEnd() {
        return current >= source.length();
    }

    bool match(char expected) {
        if(isAtEnd()) {
            return false;
        }

        if(source.at(current) != expected) {
            return false;
        }

        ++current;
        return true;
    }

    void scanToken() {
        char c = advance();
        switch (c) {
            case '(': addToken(TokenType::LEFT_PAREN); break;
            case ')': addToken(TokenType::RIGHT_PAREN); break;
            case '{': addToken(TokenType::LEFT_BRACE); break;
            case '}': addToken(TokenType::RIGHT_BRACE); break;
            case ',': addToken(TokenType::COMMA); break;
            case '.': addToken(TokenType::DOT); break;
            case '-': addToken(TokenType::MINUS); break;
            case '+': addToken(TokenType::PLUS); break;
            case ';': addToken(TokenType::SEMICOLON); break;
            case '*': addToken(TokenType::STAR); break;
            case '!':
                addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
                break;
            case '=':
                addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
                break;
            case '<':
                addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
                break;
            case '>':
                addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
                break;

            case '/':
                if (match('/')) {
                    // A comment goes until the end of the line.
                    while(peek() != '\n' && !isAtEnd()) {
                        advance();
                    }
                } else {
                    addToken(TokenType::SLASH);
                }
                break;
            
            case ' ':
            case '\r':
            case '\t':
                // Ignore whitespace.
                break;
            
            case '\n':
                line++;
                break;

            case '"':
                string();
                break;

            default:
                error(line, "Unexpected character."); // error() method from Error.h file
                break;

        };
    }

    void string() {
        while(peek() != '"' && !isAtEnd()) {
            if(peek() == '\n') line++;
            advance();
        }

        if(isAtEnd()) {
            error(line, "Unterminated string.");
            return;
        }

        // The closing ".
        advance();

        // Trim the surrounding quotes.
        std::string value = source.substr(start + 1, current - 1);
        addToken(TokenType::STRING, value);
    }

    char advance() {
        // consumes the next character in the source file and returns it.
        return source.at(current++);
        // return source[current++];
    }

    void addToken(TokenType type) {
        addToken(type, "");
        // addToken(type, nullptr);
    }

    void addToken(TokenType type, std::string literal) {
        // it grabs the text of the current lexeme and creates a new token for it
        std::string text = source.substr(start, current - start);
        tokens.push_back(Token(type, text, literal, line));
    }

    char peek() {
        if (isAtEnd()) {
            return '\0';
        }

        return source.at(current);
    }


};