#include <iostream>
#include <string>


int main(int argc, char **argv) {
    if(argc =! 1) {
        std::cout << "Usage: generate_ast <output directory>" << std::endl;
        exit(64);
    }

    std::string output_dir = argv[0];
}