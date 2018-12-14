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
    Writer* writer = new Writer("./test.asm", argv[2]);
    while(std::getline(file, line)){
        int type = parser.CommandType(line);
        parser.ProcessLine(type, line, *writer);
    }
    file.close();
}