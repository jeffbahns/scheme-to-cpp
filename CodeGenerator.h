#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class CodeGenerator {
 public:
    CodeGenerator(char * filename);
    ~CodeGenerator();
    void write(string code_to_write);
    void define(string function_name);
    void end_define();
    void param(string param);
    void end_param();    
    void literal();

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
    bool middle_param; // if in middle of param list use ',' to separate params
    bool main_function; // to check if we are in middle of generating main file, has differnent return type pretty much
    ofstream cppfile;
    
};

#endif
