#include "parser.h"
#include <regex>
#include <iostream>
#include <stdio.h>
#include <string.h>

int CommandType(std::string line){
    std::string subject(line);
    std::string result;
    int type = 3;
    try {
        std::regex pushPopRe("^(.*)\\s+(.*)\\s+(.*)");
        std::regex operationRe(".*(add|sub|neg|eq|get|lt|and|or|not).*");
        std::smatch match;
        if (std::regex_search(subject, match, pushPopRe) && match.size() > 1) {
            type = PARSER_PUSH_POP_COMMAND;
        } 
        else if(std::regex_search(subject, match, operationRe) && match.size() > 1){
            type = PARSER_OPERATION_COMMAND;
        }
    } catch (std::regex_error& e) {
    }
    return type;
}