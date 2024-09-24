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