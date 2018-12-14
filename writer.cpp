#include "writer.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Writer::Writer(std::string filePath, std::string fileName){
    this->filePath = filePath;
    this->fileName = fileName;
}

void Writer::WritePushPop(std::string command, std::string segment, std::string index){
    int type = SegmentType(command);
    if(command == "pop") WritePop(type, segment, index);
    if(command == "push") WritePush(type, segment, index);
}

void Writer::WriteBasicPush(std::string segment, std::string index){
    std::ofstream outputStream;
    std::ostringstream stringstream;
    outputStream.open(this->filePath, std::ios_base::app);
    stringstream << "@"           << SegmentTranslation(segment) << std::endl;
    stringstream << "D=M"         << std::endl;
    stringstream << "@"           << index << std::endl;
    stringstream << "D=D+A"       << std::endl;
    stringstream << "@R1"         << std::endl;
    stringstream << "M=D"         << std::endl; 
    stringstream << "@SP"         << std::endl;
    stringstream << "M=D"         << std::endl;
    stringstream << "@SP"         << std::endl;
    stringstream << "A=A+1"       << std::endl;
    outputStream << stringstream.str();
    outputStream.close();
}

void Writer::WriteBasicPop(std::string segment, std::string index){
    std::ofstream outputStream;
    std::ostringstream stringstream;
    outputStream.open(this->filePath, std::ios_base::app);
    stringstream << "@"           << SegmentTranslation(segment) << std::endl;
    stringstream << "D=M"         << std::endl;
    stringstream << "@"           << index << std::endl;
    stringstream << "D=D+A"       << std::endl;
    stringstream << "@R1"         << std::endl;
    stringstream << "M=D"         << std::endl;
    stringstream << "@SP"         << std::endl;
    stringstream << "A=A-1"       << std::endl;
    stringstream << "@R1"         << std::endl;
    stringstream << "M=D"         << std::endl;
    stringstream << "@SP"         << std::endl;
    stringstream << "D=M"         << std::endl;
    outputStream << stringstream.str();
    outputStream.close();
}

void Writer::WriteConstantTranslation(std::string segment, std::string index){
    std::ofstream outputStream;
    std::ostringstream stringstream;
    outputStream.open(this->filePath, std::ios_base::app);
    stringstream << "@" << index << std::endl;
    stringstream << "D=A" << std::endl;
    stringstream << "@SP" << std::endl;
    stringstream << "M=D" << std::endl;
    stringstream << "A=A+1" << std::endl;
    outputStream << stringstream.str();
    outputStream.close();
}

void Writer::WriteStaticPush(std::string segment, std::string index){
    std::ofstream outputStream;
    std::ostringstream stringstream;
    outputStream.open(this->filePath, std::ios_base::app);
    stringstream << "@" << index << std::endl;
    stringstream << "D=A" << std::endl;
    stringstream << "@SP" << std::endl;
    stringstream << "M=D" << std::endl;
    stringstream << "A=A+1" << std::endl;
    outputStream << stringstream.str();
    outputStream.close();
}

void Writer::WriteStaticPop(std::string segment, std::string index){
    std::ofstream outputStream;
    std::ostringstream stringstream;
    outputStream.open(this->filePath, std::ios_base::app);
    stringstream << "";
}

void Writer::WriteStaticPush(std::string segment, std::string index){
    std::ofstream outputStream;
    std::ostringstream stringstream;
    outputStream.open(this->filePath, std::ios_base::app);
    stringstream << fileName << "." << index << std::endl; 
    stringstream << "" << std::endl;
    outputStream << stringstream.str();
    outputStream.close();
}

void Writer::WriteArithmetic(std::string command){
    std::ofstream outputStream;
    std::ostringstream stringStream;
    outputStream.open(this->filePath, std::ios_base::app);
}

int Writer::SegmentType(std::string segment){
    if(segment == "local") return LOCAL_TYPE;
    if(segment == "this") return THIS_TYPE;
    if(segment == "that") return THAT_TYPE;
    if(segment == "argument") return ARGUMENT_TYPE;
    if(segment == "temp") return TEMP_TYPE;
    if(segment == "constant") return CONSTANT_TYPE; 
    if(segment == "static") return STATIC_TYPE; 
    throw std::invalid_argument("No segment type found for segment");
}

std::string Writer::SegmentTranslation(std::string segment){
    if(segment == "local") return LOCAL;
    if(segment == "this") return THIS;
    if(segment == "that") return THAT;
    if(segment == "argument") return ARGUMENT;
    if(segment == "temp") return TEMP;
    if(segment == "constant") return CONSTANT; 
    if(segment == "static") return STATIC; 
    throw std::invalid_argument("No segment translation found for segment");
}

void Writer::WritePush(int type, std::string segment, std::string index){
    if(type == LOCAL_TYPE) WriteBasicPush(segment, index);
    if(type == THIS_TYPE) WriteBasicPush(segment, index);
    if(type == THAT_TYPE) WriteBasicPush(segment, index);
    if(type == ARG_TYPE) WriteBasicPush(segment, index);
    if(type == CONSTANT_TYPE) WriteConstantTranslation(segment, index);
    if(type == STATIC_TYPE) WriteStaticPush(segment, index);
}

void Writer::WritePop(int type, std::string segment, std::string index){
    if(type == LOCAL_TYPE) WriteBasicPop(segment, index);
    if(type == THIS_TYPE) WriteBasicPop(segment, index);
    if(type == THAT_TYPE) WriteBasicPop(segment, index);
    if(type == ARG_TYPE) WriteBasicPop(segment, index);
    if(type == STATIC_TYPE) WriteStaticPop(segment, index);
}
