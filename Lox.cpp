#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <vector>
#include <sstream>


class Lox {

    //private: 
    public:
    Lox() {

    }; 

    void runFile(const std::string& path) {
        // Open the file in binary mode
        std::ifstream file(path, std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "Error msg: Could not open file '" << path << "'" << std::endl;
            exit(64);
        }

        std::stringstream bytes;

        bytes << file.rdbuf();

        run(bytes.str());

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
        }
    }

    void run(std::string source) {
        std::cout << source << std::endl;
        // std::cout << "Code is running 'run() function'" << std::endl;
    }

};


int main(int argc, char* argv[]) {
    Lox lox;

    if (argc > 2) {
        std::cout << "Usage: CPPLox [scripts]" << std::endl;
        exit(64);
    } else if (argc == 2) {
        lox.runFile(argv[0]);
        //runFile(argv[0]);
    } else {
        lox.runPrompt();
        //runPrompt();
    }
}

