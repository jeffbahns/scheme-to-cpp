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

void CodeGenerator::predicate()
{
    
}

void CodeGenerator::lessT()
{
    
}

void CodeGenerator::gT()
{
    
}

void CodeGenerator::equal()
{
    
}

void CodeGenerator::notEqual()
{
    
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
