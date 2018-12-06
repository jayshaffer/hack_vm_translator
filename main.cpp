#include "parser.h"
#include "builder.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv){
    std::ifstream file(argv[1]); 
    std::string line;
    while(std::getline(file, line)){
        std::cout << 1;
        std::cout << line;
        std::cout << CommandType(line);
    }
}