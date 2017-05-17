#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(char * filename) {
    cppfile.open(filename, std::ofstream::out);
    //cppfile.open(filename);
    cout << "opening " << filename << endl;

    cppfile << "#include <iostream>" << endl;
    cppfile << "using namespace std;" << endl;
    write("hi");
}

CodeGenerator::~CodeGenerator() {
    cppfile.close();
}

void CodeGenerator::write(string code_to_write) {
    cppfile << code_to_write << endl;
}

void CodeGenerator::define(string function_name) {
    //cout << function_name << endl;
    cppfile << " " << endl;
}

