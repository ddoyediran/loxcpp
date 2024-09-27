#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class GenerateAst {
    
    public:
    GenerateAst() {}

    void defineAst(const std::string outputDir, const std::string baseName, const std::vector<std::string> types) {
        std::string path = outputDir + "/" + baseName + ".cpp";
        std::ofstream writer{path};

        writer << "#pragma once" << std::endl;
        writer << std::endl;

        writer << "#include <vector>" << std::endl;
        writer << std::endl;

        writer << "class " << baseName << " {" << std::endl;

        // The AST classes.


        writer << "}" << std::endl;
        writer.close();

    }

    private:
    std::string_view trim(std::string_view str) {
        std::size_t end = str.size() - 1;

        std::size_t start = 0;
        
        while(start <= end && std::isspace(str[start])) {
            ++start;
        }

        while(end >= start && std::isspace(str[end])) {
            --end;
        }
        
        return str.substr(start, end - start + 1);
    }
    
};

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cout << "Usage: generate_ast <output directory>" << std::endl;
        std::exit(64);
    }

    std::string outputDir = argv[1];

    GenerateAst generateAst;

    generateAst.defineAst(outputDir, "Expr", {
        "Binary   : Expr left, Token operator, Expr right",
        "Grouping : Expr expression",
        "Literal  : Object value",
        "Unary    : Token operator, Expr right"
    });

}