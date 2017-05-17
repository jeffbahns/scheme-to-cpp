#include "CodeGenerator.h"

CodeGenerator::CodeGenerator(char * filename) {
    middle_param = false;

    cppfile.open(filename, std::ofstream::out);
    cout << "opening " << filename << endl;
    write("#include <iostream>\n");
    write("using namespace std;\n\n");
}

CodeGenerator::~CodeGenerator() {
    cppfile.close();
}

void CodeGenerator::write(string code_to_write) {
    cppfile << code_to_write;
}

void CodeGenerator::define(string function_name) {
    if (function_name == "main") {
	write("int ");
    } else {
	write("Object ");
    }
    write(function_name + "(");	
}

void CodeGenerator::end_define() {
    write("}\n\n");
}

void CodeGenerator::param_list(vector<string> *params) {
    for (int i = 0; i < params->size(); i++) {
	write(params->at(i) + " ");
    }
}

void CodeGenerator::param(string param) {
    if (middle_param) { // if in middle of param list use ',' to separate params
	write(", ");
    } else {
	middle_param = true;
    }
    write("Object " + param);
}

void CodeGenerator::end_param() {
    write(") {\n");
    middle_param = false;
}

void CodeGenerator::predicate()
{
    
}

void CodeGenerator::lessT(string first, string second)
{
    cppfile << "(" << first << " < " << second << ")" << endl;
}

void CodeGenerator::gT(string first, string second)
{
    cppfile << "(" << first << " > " << second << ")" << endl;
}

void CodeGenerator::equal(string first, string second)
{
    cppfile << "(" << first << " == " << second << ")" << endl;
}

void CodeGenerator::notEqual(string first, string second)
{
    cppfile << "(" << first << " != " << second << ")" << endl;
}

void CodeGenerator::plus()
{
    
}

void CodeGenerator::minus()
{
    
}

void CodeGenerator::mult()
{
    
}

void CodeGenerator::div()
{
    
}

void CodeGenerator::ident()
{
    
}

void CodeGenerator::cons()
{
    
}

void CodeGenerator::listop()
{
    
}

void CodeGenerator::ifStatement()
{
    
}

void CodeGenerator::display()
{
    
}
