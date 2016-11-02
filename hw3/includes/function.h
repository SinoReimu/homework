#include <iostream>
#include <cstring>

using namespace std;
#ifndef FUNCTION_H
#define FUNCTION_H

typedef void (*function) (string a, string* b, int c);
void exit (string, string*, int);
void choose(string, string*, int);
void tree(string, string*, int);
bool cal (string s, bool* values);

#endif
