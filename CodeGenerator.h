#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <fstream>

using namespace std;

class CodeGenerator {

 public:
    CodeGenerator(char * filename);
    ~CodeGenerator();
    void Define(...);
    void Predicate(...);
    void LT(...);
    void GT(...);
    void Equal(...);
    void NotEqual(...);
    void Plus(...);
    void Minus(...);
    void Mult(...);
    void Div(...);
    void Ident(...);
    void Cons(...);
    void Listop(...);
    void If(...);
    void Display();
    
 private:
    ofstream cppfile;
    
};

#endif
