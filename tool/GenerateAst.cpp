#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cout << "Usage: generate_ast <output directory>" << std::endl;
        std::exit(64);
    }

    std::string output_dir = argv[1];

}