#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <sstream>

enum Token_value
{
    NUMBER, END, PRINT,
    PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
    LP = '(', RP = ')', POWER = '^',
};

double exprf(bool);
double term(bool);
double prim(bool);
double highpr(bool);
Token_value get_token();
std::string receive(std::string);
double error(const std::string&);

#endif // PARSER_H
