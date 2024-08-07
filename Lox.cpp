#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <vector>
#include <sstream>


class Lox {

    private: 
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

    }

    void run(std::string source) {
        
    }

};


int main(int argc, char* argv[]) {
    // std::cout << "You've enter " << argc << " arguments." << std::endl;
    // // std::cout << "ARGV length: " << argv << "arguments" << std::endl;

    // int i = 0;

    // while (i < argc) {
    //     std::cout << "Arg " << i + 1 << ": " << argv[i] << std::endl;
    //     i++;
    // }

    if (argc > 1) {
        std::cout << "Usage: cpplox [scripts]" << std::endl;
        exit(64);
    } else if (argc == 1) {
        runFile(argv[0]);
    } else {
        runPrompt();
    }
}

