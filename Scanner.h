#include <string>
#include <string_view>
#include <vector>
#include <iostream>
#include <utility> // to use std::move

#include "Token.h"
//#include "TokenType.h"
#include "Error.h"

class Scanner {
    private:
    std::string_view source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;

    public:
    // Scanner() : start(0), current(0), line(0) {}

    Scanner(std::string_view source) : source{source} {
        // source = source;
    }

    std::vector<Token> scanTokens() {
        while (!isAtEnd()) {
            // We are at the beginning of the next lexeme.
            start = current;
            scanToken();
        }

        // Token token(TokenType::END_OF_FILE, "", NULL, line);
        // tokens.push_back(token);

        // tokens.push_back(Token(TokenType::END_OF_FILE, "", "", line));
        // tokens.push_back(Token(TokenType::END_OF_FILE, "", nullptr, line));
        tokens.emplace_back(TokenType::END_OF_FILE, "", nullptr, line);
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

        if(source[current] != expected) {
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
                if(isDigit(c)) {
                    number();
                } else {
                    error(line, "Unexpected character."); // error() method from Error.h file
                }
                break;
        };
    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    void number() {
        while(isDigit(peek())) advance();

        // Look for a fractional part.
        if( peek() == '.' && isDigit(peekNext())) {
            // Consume the "."
            advance();

            while(isDigit(peek())) advance();
        }

        addToken(TokenType::NUMBER, std::stod(std::string{source.substr(start, current - start)}));

        // addToken(TokenType::NUMBER, std::stod(std::string{source.substr(start, current - start)}));
    }

    void string() {
        while(peek() != '"' && !isAtEnd()) {
            if(peek() == '\n') ++line;
            advance();
        }

        if(isAtEnd()) {
            error(line, "Unterminated string.");
            return;
        }

        // The closing ".
        advance();

        // Trim the surrounding quotes.
        // std::string value = source.substr(start + 1, current - 2 - start);
        std::string value {source.substr(start + 1, current - 2 - start)};
        addToken(TokenType::STRING, value);
    }

    char advance() {
        // consumes the next character in the source file and returns it.
        return source[current++];
        // return source[current++];
    }

    void addToken(TokenType type) {
        // addToken(type, "");
        addToken(type, nullptr);
    }

    void addToken(TokenType type, std::any literal) {
        // it grabs the text of the current lexeme and creates a new token for it
        // std::string text = source.substr(start, current - start);
        std::string text{source.substr(start, current - start)};
        // tokens.push_back(Token(type, text, literal, line));
        tokens.emplace_back(type, std::move(text), std::move(literal), line);
    }

    char peek() {
        if (isAtEnd()) {
            return '\0';
        }

        return source[current];
    }

    char peekNext() {
        if (current + 1 >= source.length()) return '\0';

        return source[current + 1];
    }

};