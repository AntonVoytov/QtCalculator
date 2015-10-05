#include "parser.h"

Token_value curr_tok = PRINT;
double number_value;
std::string expression;
int  no_of_errors;

double exprf(bool get)
{
    double left = term(get);
    while(1)
    {
        switch(curr_tok)
        {
            case PLUS:
                left += term(true);
                break;
            case MINUS:
                left -=term(true);
                break;
            default:
                return left;
        }
    }
}

double term(bool get)
{
    double left = highpr(get);
    while(1)
    {
        switch(curr_tok)
        {
            case MUL:
                left *= highpr(true);
                break;
            case DIV:
                if (double d = highpr(true))
                {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}

double highpr(bool get)
{
    double left = prim(get);
    while(1)
    {
        switch(curr_tok)
        {
            case POWER:
                left = pow(left, prim(true));
                break;
            default:
                return left;
        }
    }
}

double prim(bool get)
{
    if (get) get_token();
    switch(curr_tok)
    {
        case NUMBER:
        {
            double v = number_value;
            get_token();
            return v;
        }
        case MINUS:
            return -prim(true);
        case LP:
        {
            double e = exprf(true);
            if(curr_tok != RP)
                return error("')' expected");
            get_token();
            return e;
        }
        default:
            return error("primary expected");
    }
}

Token_value get_token()
{
    char ch = 0;
    static int i = 0;
    std::string part;
    if (expression.size() == 0)
            return curr_tok = PRINT;
    ch = expression[0];

    switch(ch)
    {
        case '\n':
            return curr_tok = END;
        case '*':
        case '/':
        case '+':
        case '-':
        case '^':
        case '%':
        case '(':
        case ')':
        case '=':
            expression.erase(expression.begin(), expression.begin() + 1);
            return curr_tok = Token_value(ch);
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            i = 0;
            while(expression.size() > i && (isdigit(expression[i]) || expression[i] == '.'))
            {
                part.push_back(expression[i]);
                i++;
            }
            number_value = atof(part.c_str());
            part.erase(part.begin(), part.end());
            expression.erase(expression.begin(), expression.begin() + i);
            return curr_tok = NUMBER;
        default:
            error("bad token");
            return curr_tok = PRINT;
    }
}

double error(const std::string &s)
{
    no_of_errors++;
    return 1;
}

std::string receive(std::string str)
{
    std::string res;
    static int func_calls_count = 0;
    if (func_calls_count > 0 && curr_tok == PRINT)
        func_calls_count = 0;
    if (func_calls_count == 0)
          expression = str;
    func_calls_count++;
    get_token();
    double resd = exprf(false);
    std::ostringstream convert;
    convert << resd;
    res = convert.str();
    return res;
}
