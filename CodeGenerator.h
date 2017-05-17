#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <fstream>

using namespace std;

class CodeGenerator {
 public:
    CodeGenerator(char * filename);
    ~CodeGenerator();
    void write(string code_to_write);
    void define(string function_name);
    void predicate();
    void lessT();
    void gT();
    void equal();
    void notEqual();
    void plus();
    void minus();
    void mult();
    void div();
    void ident();
    void cons();
    void listop();
    void ifStatement();
    void display();
    
 private:
    ofstream cppfile;
    
};

#endif
