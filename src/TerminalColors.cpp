#include "TerminalColors.hpp"

string str_red(string text)
{
    return "\033[31;1m" + text + "\033[0m";
}
string str_blue(string text)
{
    return "\033[34;1m" + text + "\033[0m";
}
string str_cyan(string text)
{
    return "\033[36;1m" + text + "\033[0m";
}
string str_green(string text)
{
    return "\033[32;1m" + text + "\033[0m";
}
string str_purple(string text)
{
    return "\033[35;1m" + text + "\033[0m";
}

