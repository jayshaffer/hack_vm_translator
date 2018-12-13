#include "parser.h"
#include "writer.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "parser_result.h"

int main(int argc, char **argv){
    std::ifstream file(argv[1]); 
    std::string line;
    Parser parser;
    Writer* writer = new Writer("./");
    while(std::getline(file, line)){
        std::istringstream iss(line);
        std::cout << line;
        std::cout << "\n";
        int type = parser.CommandType(line);
        std::ofstream stream("./test.asm");
        parser.ProcessLine(type, line, *writer);
    }
    file.close();
}