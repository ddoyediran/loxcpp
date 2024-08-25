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
        std::cout << "runPrompt called" << std::endl;
    }

    void run(std::string source) {
        std::cout << "Code is running 'run() function'" << std::endl;
    }

};


int main(int argc, char* argv[]) {
    Lox lox;

    if (argc > 1) {
        std::cout << "Usage: cpplox [scripts]" << std::endl;
        exit(64);
    } else if (argc == 1) {
        lox.runFile(argv[0]);
        //runFile(argv[0]);
    } else {
        lox.runPrompt();
        //runPrompt();
    }
}

