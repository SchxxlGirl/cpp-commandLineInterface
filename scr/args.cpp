#define _CRT_SECURE_NO_WARNINGS

#include "../inc/args.h"

#include<cstring>

Args::~Args()
{
    for(int i = 0; i < _args_count; i ++)
        delete [] _args[i];
    if (_args != nullptr)
        delete [] _args;
}

Args::Args(const Args& other)
{
    this->_args_count = other._args_count;
    
    this->_args = new char*[_args_count];

    for (int i = 0; i < _args_count; i ++)
    {
        _args[i] = new char[strlen(other._args[i] + 1)];
        strcpy(_args[i], other._args[i]);
    }
}

void Args::add_arg(const char *arg)
{
    char **temp = new char* [_args_count + 1];

    for(int i = 0; i < _args_count; i ++)
        temp[i] = _args[i];

    temp[_args_count] = new char[strlen(arg) + 1];
    strcpy(temp[_args_count], arg);

    _args_count ++;

    delete [] _args;
    _args = temp;
}

const char* Args::get_arg(int i) const
{
    if (i >= 0 && i < _args_count)
       return _args[i];
    return nullptr;
}

int Args::get_count() const
{
    return _args_count;
}
