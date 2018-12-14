#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "parser_result.h"
#include "writer.h"

const std::string PUSHPOP_RE = "^(push|pop)\\s+(.*)\\s+(\\d+).*";
const std::string ARITH_RE = "^((:?add|sub|neg|eq|get|lt|and|or|not)).*";
const int PARSER_MEM_COMMAND = 0;
const int PARSER_LOGIC_COMMAND = 1;
const int PARSER_INVALID_COMMAND = 2;

class Parser{
    public:
        int CommandType(std::string line);
        ParserResult PushPopParts(std::string line); 
        void ProcessLine(int type, std::string line, Writer writer);
};

#endif