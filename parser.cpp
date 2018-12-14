#include "parser.h"
#include <regex>
#include <iostream>
#include <string>

int Parser::CommandType(std::string line){
    std::string subject(line);
    int type = PARSER_INVALID_COMMAND;
    try {
        std::regex pushPopRe(PUSHPOP_RE);
        std::regex operationRe(ARITH_RE);
        std::smatch match;
        if (std::regex_search(subject, match, pushPopRe) && match.size() > 1) {
            type = PARSER_MEM_COMMAND;
        } 
        else if(std::regex_search(subject, match, operationRe) && match.size() > 1){
            type = PARSER_LOGIC_COMMAND;
        }
    } catch (std::regex_error& e) {
    }
    return type;
}

void Parser::ProcessLine(int type, std::string line, Writer writer){
    Parser parser;
    switch(type){
        case PARSER_MEM_COMMAND:
        {
            ParserResult result = PushPopParts(line);
            writer.WritePushPop(result.arg1, result.arg2, result.arg3);
            break;
        }
        case PARSER_LOGIC_COMMAND:
        {
            break;
        }
    }
}

ParserResult Parser::PushPopParts(std::string line){
    std::smatch match;
    std::regex re(PUSHPOP_RE);
    std::regex_search(line, match, re);
    std::string arg1 = match.str(1);
    std::string arg2 = match.str(2);
    std::string arg3 = match.str(3);

    return ParserResult(arg1, arg2, arg3);
}