#ifndef PARSER_H
#define PARSER_H
#define PARSER_PUSH_POP_COMMAND 0
#define PARSER_OPERATION_COMMAND 1
#define PARSER_INVALID_COMMAND 2

#include <stdio.h>
#include <string>
int CommandType(std::string line);

#endif