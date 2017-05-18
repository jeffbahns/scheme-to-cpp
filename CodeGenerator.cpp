#include "CodeGenerator.h"

const string tab = "    "; // const used to quickly tab 

CodeGenerator::CodeGenerator(char * filename) {
    middle_param = false;
    main_function = false;
    
    cppfile.open(filename, std::ofstream::out);
    cout << "opening " << filename << endl;
    write("#include \"Object.cpp\"\n");
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
	main_function = true;
    } else {
	write("Object ");
    }
    write(function_name + "(");	
}

void CodeGenerator::end_define() {
    if (main_function) {
	main_function = false;
    } else {
	write("return ret;\n");	
    }

    write("}\n\n");
}

void CodeGenerator::param(string param) {
    if (middle_param) {
	write(", ");
    } else {
	middle_param = true;
    }
    write("Object " + param);
}

void CodeGenerator::end_param() {
    write(") {\n");
    if (main_function) {
	write("int ret;\n"); // ? don't know if we do this for main..
    } else {
	write("Object ret;\n");	
    }
    middle_param = false;
}

void CodeGenerator::stmt_ident(string ident, bool returned) {
    if (returned) {
	write("ret = " + ident + ";\n");	
    } else {
	write(ident);	
    }
}

void CodeGenerator::num_literal(string lit, bool returned) {
    if (returned) {
	if (main_function) {
	    write("ret = " + lit + ";\n");
	} else {
	    write("ret = Object(" + lit + ");\n");
	}
    } else {
	write("Object(" + lit + ")");
    }
}

void CodeGenerator::quoted_literal(string lit, bool returned) {
    if (returned) {
	if (main_function) {
	    write("ret = " + lit + ";\n");
	} else {
	    write("ret = Object(\"" + lit + "\");\n");
	}
    } else {
	write("Object(\"" + lit + "\")");
    }
}

void CodeGenerator::if_begin() {
    write("if (");
}

void CodeGenerator::if_cond_end() {
    write(") {\n");
}

void CodeGenerator::if_else_part() {
    write("} else {\n");
}

void CodeGenerator::if_else_part_end() {
    write("}\n");
}

void CodeGenerator::listop_begin(string listop, bool returned) {
    if (returned) {
	write("ret = ");
    } 
    write("listop(\"" + listop + "\", ");	
}

void CodeGenerator::listop_end(bool returned, bool nested) {
    write(")");
    if (returned && !nested) {
	write(";\n");
    } 
}

void CodeGenerator::cons_begin(bool returned) {
    if (returned) {
	write("ret = ");
    }
    write("cons(");
}

void CodeGenerator::cons_end(bool returned, bool nested) {
    write(")");
    if (returned && !nested) {
	write(";\n")
    }
}

void CodeGenerator::lessT(string first, string second)
{
    cppfile << "(" << first << " < " << second << ")" << endl;
}

void CodeGenerator::gT(string first, string second)
{
    cppfile << "(" << first << " > " << second << ")" << endl;
}

void CodeGenerator::newline() {
  cppfile << "cout<<endl;"<<endl;
}

void CodeGenerator::display() {
    write("cout << ");
}

void CodeGenerator::endDisplay() {
    write(" << endl;\n");
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
/*
void CodeGenerator::cons(string op1, string op2) {
  cppfile<<"cons(" << op1 << "," <<op2 <<");"<<endl;
}
*/


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

void CodeGenerator::equal(string first, string second)
{
    cppfile << "(" << first << " == " << second << ")" << endl;
}

void CodeGenerator::notEqual(string first, string second)
{
    cppfile << "(" << first << " != " << second << ")" << endl;
}

void CodeGenerator::ident()
{
    
}
