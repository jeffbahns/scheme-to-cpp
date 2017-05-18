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

    //comparisons
    void predicate(string,string);
    void lessT();
    void greaterT();
    void ltE();
    void gtE();
    void equal();
    void notEqual();

    //math
    string plus(vector<string>);
    string minus(vector<string>);
    string mult(vector<string>);
    string div(vector<string>);
    
    void ident();
    void cons(string, string);
    void listop(string,string);
    void ifStatement(string, vector<string>, vector<string>);
    void display();
    void endDisplay();
    void newline();
    
 private:
    ofstream cppfile;
    
};

#endif
