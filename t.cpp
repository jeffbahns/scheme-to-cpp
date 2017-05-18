#include "Object.cpp"
#include <iostream>
using namespace std;

Object opraw(Object t) {
Object ret;
 if (listop("car", listop("cdr", t))) {
     cout << Object("hello_world") << endl;
 } else {
 }
 return ret;
}

int main() {
    int ret;
    ret = 0;
}

