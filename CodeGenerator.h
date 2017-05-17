#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <fstream>

using namespace std;

class CodeGenerator {

 public:
    CodeGenerator(char * filename);
    ~CodeGenerator();
 private:
    ofstream cppfile;
    
};

#endif
