#pragma once

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class ParserResult{
     public:
        ParserResult(std::string arg1, std::string arg2, std::string arg3);
        string arg1;
        string arg2;
        string arg3;
};