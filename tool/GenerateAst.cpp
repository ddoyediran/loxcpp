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

        writer << "#pragma once";
        writer << std::endl;

        writer << "#include <vector>";
        writer << std::endl;

        writer << "class " << baseName << " {" << std::endl;

        // The AST classes.
        for (std::string type: types) {
            std::vector<std::string> splittedExpr = split(type, ':');

            std::string classname = trim(splittedExpr[0]);
            std::string fields = trim(splittedExpr[1]);
        }


        writer << "}" << std::endl;
        writer.close();

    }

    private:
    std::string trim(std::string str) {
        /**
         * Trim white space(s) from the front and back of a string.
         * @Params str: std::string.
         * Returns str std::string.
         */
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

    std::vector<std::string> split(std::string_view str, char separator) {
        /**
         * Split a string into an array of strings.
         * Splits this string around matches of the given regular expression.
         * Returns a std::vector<std::string>
         */
        std::vector<std::string> splitResult = {};

        std::string splittedString = "";

        // loop through the string
        for(int i = 0; i < str.size(); ++i) {
            // if the char != separator concatenate it to the splittedString 
            if(str[i] != separator) {
                splittedString += str[i];
            } else {
                // if the char == separator, push the splittedString to splitResult vector and reset splittedString to empty string
                splitResult.push_back(splittedString);
                splittedString = "";
            }

        }

        if (!splittedString.empty()) {
            splitResult.push_back(splittedString);
        }

        return splitResult;
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