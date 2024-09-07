#pragma once

#include <iostream>
#include <string>


bool hadError = false;


void report(int line, std::string where, std::string message) {
    std::cout << "[line " << line << "] Error" << where << ": " << message << std::endl;

    hadError = true;
}

void error(int line, std::string message) {
    report(line, "", message);
}