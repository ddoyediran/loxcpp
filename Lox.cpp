#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <vector>
#include <sstream>

#include "Scanner.h"
#include "Error.h"


class Lox {

    //private: 
    // bool hadError;

    public:
    Lox() {
        // hadError = false;
    }; 

    // Lox() : hadError(false) {
    //     // hadError = false;
    // }; 

    void runFile(const std::string& path) {
        // Open the file in binary mode and read the contents
        std::ifstream file(path, std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "Error msg: Could not open file '" << path << "'" << std::endl;
            exit(64);
        }

        std::stringstream bytes;

        bytes << file.rdbuf();

        run(bytes.str());

        // optional: destructor automatically calls the member function close - because the object is destroyed 
        // file.close(); 

        // Indicate an error in the exit code.
        if (hadError) {
            exit(65);
        }

    }

    void runPrompt() {
        /**
         * Function read user input typed on the terminal/ console.
         * @param: null
         * Returns: void
         */
        std::string line;

        while(true) {
            std::cout << "> ";

            getline(std::cin, line);

            if(line.empty()) {
                break;
            }

            run(line);
            hadError = false;
        }
    }

    void run(std::string_view source) {
        Scanner scanner {source};

        std::vector<Token> tokens = scanner.scanTokens();

        // for(const Token& token : tokens) {
        //     std::cout << token << std::endl;
        // }

        for(const Token& token : tokens) {
            std::cout << token.toString() << std::endl;
            // std::cout << token << std::endl;
        }
    }


};


int main(int argc, char* argv[]) {
    Lox lox;

    if (argc > 2) {
        std::cout << "Usage: CPPLox [scripts]" << std::endl;
        exit(64);
    } else if (argc == 2) {
        // lox.runFile(argv[0]);
        lox.runFile(argv[1]);
        //runFile(argv[0]);
    } else {
        lox.runPrompt();
        //runPrompt();
    }
}
