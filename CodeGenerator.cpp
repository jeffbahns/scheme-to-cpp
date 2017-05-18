#include "CodeGenerator.h"

const string tab = "    "; // const used to quickly tab 
int tab_level = 0;
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
	//write("int ");
	main_function = true;
    } else {
	write("Object ");
    }
    write(function_name + "(");	
}

void CodeGenerator::end_define() {
    if (main_function) {
	write("return 0;\n");
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
	//write("int ret;\n"); // ? don't know if we do this for main..
    } else {
	write("Object ret;\n");	
    }
    middle_param = false;
}

void CodeGenerator::stmt_ident(string ident, bool return_val) {
    if (return_val) {
	write("ret = " + ident + ";\n");	
    } else {
	write(ident);	
    }
}

void CodeGenerator::num_literal(string lit, bool return_val) {
    if (return_val) {
	if (main_function) {
	    //write("ret = " + lit + ";\n");
	} else {
	    write("ret = Object(" + lit + ");\n");
	}
    } else {
	write("Object(" + lit + ")");
    }
}

void CodeGenerator::quoted_literal(string lit, bool return_val) {
    if (return_val) {
	if (main_function) {
	    //write("ret = " + lit + ";\n");
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

/* GENERAL ACTIONS (not including "if") */
void CodeGenerator::action_begin(string to_write, bool return_val) {
    if (return_val) {
	write("ret = ");
    }
    write(to_write);
}

void CodeGenerator::action_end(bool return_val, bool is_nested) {
    write(")");
    if (return_val && !is_nested) {
	write(";\n");
    } 
}

// 44
void CodeGenerator::display() {
    write("cout << ");
}

void CodeGenerator::endDisplay() {
    write(" << endl;\n");
}

void CodeGenerator::lessT(string first, string second)
{
    cppfile << "(" << first << " < " << second << ")" << endl;
}

void CodeGenerator::gT(string first, string second)
{
    cppfile << "(" << first << " > " << second << ")" << endl;
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

void CodeGenerator::equal(string first, string second)
{
    cppfile << "(" << first << " == " << second << ")" << endl;
}


