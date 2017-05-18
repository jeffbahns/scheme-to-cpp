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
    
    void stmt_ident(string ident, bool return_val); // rule 8
    void num_literal(string lit, bool return_val); // rule 7->10
    void quoted_literal(string lit, bool return_val); // rule 11
    
    /* ACTIONS, grouped by similar structure*/
    void if_begin(); // rule 19
    void if_cond_end();
    void if_else_part();
    void if_else_part_end();

    void action_begin(string to_write, bool return_val); // rules 20->41, 43
    void action_end(bool return_val, bool is_nested);
    /**/
    void display(); // rule 42
    void endDisplay();
    /**/

 private:
    bool middle_param; // if in middle of param list use ',' to separate params
    bool main_function; // to check if we are in middle of generating main file, has differnent return type pretty much
    string current_op;
    ofstream cppfile;
    
};

#endif
