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

void CodeGenerator::newline() {
  cppfile << "cout<<endl;"<<endl;
}

void CodeGenerator::display() {
  cppfile<<"cout<<";
}

void CodeGenerator::endDisplay() {
  cppfile<<";";
}

string CodeGenerator::plus(vector<string> operands) {
  string writable = "";
  if(!operands.empty())
    writable+= "("+operands[0];
  for(int i=1;i<operands.size();i++)
    {
      writable+=" + "+operands[i];
    }
  if(!operands.empty())
    writable+= ");";
  cppfile<<writable<<endl;
  return writable;
}

string CodeGenerator::minus(vector<string> operands) {
  string writable = "";
  if(!operands.empty())
    writable+= "("+operands[0];
  for(int i=1;i<operands.size();i++)
    {
      writable+=" - "+operands[i];
    }
  if(!operands.empty())
    writable+= ");";
  cppfile<<writable<<endl;
  return writable;
}

string CodeGenerator::mult(vector<string> operands) {
  string writable = "";
  if(!operands.empty())
    writable+= "("+operands[0];
  for(int i=1;i<operands.size();i++)
    {
      writable+=" * "+operands[i];
    }
  if(!operands.empty())
    writable+= ");";
  cppfile<<writable<<endl;
  return writable;
}

string CodeGenerator::div(vector<string> operands) {
  string writable = "";
  if(!operands.empty())
    writable+= "("+operands[0];
  for(int i=1;i<operands.size();i++)
    {
      writable+=" / "+operands[i];
    }
  if(!operands.empty())
    writable+= ");";
  cppfile<<writable<<endl;
  return writable;
}

void CodeGenerator::cons(string op1, string op2) {
  cppfile<<"cons(" << op1 << "," <<op2 <<");"<<endl;
}

void CodeGenerator::listop(string listop, string list) {
  cppfile<<"listop(" <<listop <<", "<<list<<");"<<endl;
}

void CodeGenerator::ifStatement(string condition, vector<string> isTrue,
				vector<string> isFalse) {
  cppfile<<"if( " <<condition <<") { \n";
  for(int i=0;i<isTrue.size();i++) {
    cppfile<<"cout<<" <<isTrue[i]<<";\n";
  }
  cppfile<<" } \n else { \n";
  for(int i=0;i<isFalse.size();i++)
    {
      cppfile<<"cout<<" <<isFalse[i]<<";\n";
    }
  cppfile<<"}"<<endl;
}

void CodeGenerator::predicate(string predType, string stmtToCheck) {
  if(predType=="number?")
    cppfile<<"numberp(";
  else if(predType=="symbol?")
    cppfile<<"symbolp(";
  else if(predType=="zero?")
    cppfile<<"zerop(";
  else if(predType=="char?")
    cppfile<<"charp(";
  else if(predType=="string?")
    cppfile<<"stringp(";
  else //null by default, arbitrarily decided by Daniel
    cppfile<<"nullp(";
  
  cppfile<<stmtToCheck<<");"<<endl;
}
