#pragma once
#include <string>
#include <fstream>

const int STACK_POINTER = 256;
const int STACK_ORIGIN_THIS = 3000;
const int STACK_POINTER_THAT = 3010;
const int STACK_POINTER_ARGUMENT = 400;
const int STACK_POINTER_LOCAL = 300;
const std::string LOCAL = "LCL";
const std::string THIS = "THIS";
const std::string THAT  = "THAT";
const std::string ARG  = "ARG";
const std::string CONSTANT  = "CONSTANT";
const std::string ARGUMENT = "ARGUMENT";

class Writer{
    public:
        Writer(std::string filePath);
        void WriteArithmetic(std::string);
        void WritePushPop(std::string command, std::string segment, std::string index);
        void WritePop(std::string command, std::string segment, std::string index);
        void WritePush(std::string command, std::string segment, std::string index);
        std::string TranslateSegment(std::string segment);
    private:
        void Write(std::string filePath);
        std::ofstream* outputStream;
};
