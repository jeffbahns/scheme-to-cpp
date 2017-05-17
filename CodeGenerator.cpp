#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(char * filename) {
    cppfile.open(filename, std::ofstream::out | std::ofstream::app);
}

CodeGenerator::~CodeGenerator() {
    cppfile.close();
}
