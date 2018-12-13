#include "writer.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Writer::Writer(std::string filePath){
    filePath = filePath;
    outputStream* = std::ofstream(filePath);
}

void Writer::WritePushPop(std::string command, std::string segment, std::string index){
    if(command == "pop") WritePop(command, segment, index);
    if(command == "push") WritePush(command, segment, index);
}

void Writer::WritePush(std::string pop, std::string segment, std::string){
    outputStream << "@"           << TranslateSegment(segment) << std::endl;
    outputStream << "D=M"         << std::endl;
    outputStream << "@"           << index << std::endl;
    outputStream << "D=D+A"       << std::endl;
    outputStream << "@R1"         << std::endl;
    outputStream << "M=D"         << std::endl; 
    outputStream << "@SP"         << std::endl;
    outputStream << "M=D"         << std::endl;
    outputStream << "@SP"         << std::endl;
    outputStream << "A=A+1"       << std::endl;
}

void Writer::WritePop(std::string pop, std::string segment, std::string index){
    std::ostringstream stream;
    outputStream << "@"           << TranslateSegment(segment) << std::endl;
    outputStream << "D=M"         << std::endl;
    outputStream << "@"           << index << std::endl;
    outputStream << "D=D+A"       << std::endl;
    outputStream << "@R1"         << std::endl;
    outputStream << "M=D"         << std::endl;
    outputStream << "@SP"         << std::endl;
    outputStream << "A=A-1"       << std::endl;
    outputStream << "@R1"         << std::endl;
    outputStream << "M=D"         << std::endl;
    outputStream << "@SP"         << std::endl;
    outputStream << "D=M"         << std::endl;
}

std::string Writer::TranslateSegment(std::string segment){
    if(segment == "local") return LOCAL;
    if(segment == "this") return THIS;
    if(segment == "that") return THAT;
    if(segment == "argument") return ARGUMENT;
    if(segment == "constant") return CONSTANT;
    return NULL;
}