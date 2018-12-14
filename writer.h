#pragma once
#include <string>
#include <fstream>

const std::string STACK_POINTER = "SP";
const std::string LOCAL = "LCL";
const std::string THIS = "THIS";
const std::string THAT  = "THAT";
const std::string ARG  = "ARG";
const std::string CONSTANT  = "CONSTANT";
const std::string ARGUMENT = "ARGUMENT";
const std::string TEMP = "TEMP";
const std::string STATIC = "STATIC";
const int LOCAL_TYPE = 0;
const int THIS_TYPE = 1;
const int THAT_TYPE = 2;
const int ARG_TYPE = 3;
const int CONSTANT_TYPE = 4;
const int ARGUMENT_TYPE = 5;
const int TEMP_TYPE = 6;
const int STATIC_TYPE = 7;

class Writer{
    public:
        std::string filePath;
        std::string fileName;
        Writer(std::string filePath, std::string fileName);
        void WriteArithmetic(std::string);
        void WritePushPop(std::string command, std::string segment, std::string index);
        void WriteBasicPop(std::string segment, std::string index);
        void WriteBasicPush(std::string segment, std::string index);
        void WriteConstantTranslation(std::string segment, std::string index);
        void WriteStaticPush(std::string segment, std::string index);
        void WriteTempPush(std::string segment, std::string index);
    private:
        void WritePush(int type, std::string segment, std::string index);
        void WritePop(int type, std::string segment, std::string index);
        void Write(std::string filePath);
        int SegmentType(std::string segment);
        std::string SegmentTranslation(std::string segment);
};
