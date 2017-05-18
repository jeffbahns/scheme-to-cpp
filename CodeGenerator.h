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
    void lessT(string first, string second);
    void gT(string first, string second);
    void equal(string first, string second);
    void notEqual(string first, string second);

    //math
    string plus(vector<string>);
    string minus(vector<string>);
    string mult(vector<string>);
    string div(vector<string>);
    
    void end_define();
    void param(string param);
    void end_param();    
    void stmt_ident(string ident, bool returned); // rule 8
    void num_literal(string lit, bool returned); // rule 7->10
    void quoted_literal(string lit, bool returned); // rule 7->11 

    void if_begin();
    void if_cond_end();

    void if_else_part();
    void if_else_part_end();

    /**/
    void beg(bool returned);
    void end(bool returned, bool nested);
    
    void listop_begin(string listop, bool returned);
    void listop(string operand);
    void listop_end(bool returned, bool nested);

    void cons_begin(bool returned);
    void cons(string operand);
    void cons_end(bool returned, bool nested);
    /**/
    
    void plus();
    void minus();
    void mult();
    void div();
    void ident();
    void cons();
    void ifStatement();
    void cons(string, string);
    void ifStatement(string, vector<string>, vector<string>);
    void display();
    void endDisplay();
    void newline();
    
 private:
    bool middle_param; // if in middle of param list use ',' to separate params
    bool main_function; // to check if we are in middle of generating main file, has differnent return type pretty much
    ofstream cppfile;
    
};

#endif
