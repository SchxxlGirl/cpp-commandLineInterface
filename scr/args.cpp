#define _CRT_SECURE_NO_WARNINGS

#include "../inc/args.h"

#include<cstring>

Args::~Args()
{
    for(int i = 0; i < _argsCount; i ++)
        delete [] _args[i];
    if (_args != nullptr)
        delete [] _args;
}

Args::Args(const Args& other)
{
    this->_argsCount = other.getCount();
    
    this->_args = new char*[this->_argsCount];

    for (int i = 0; i < this->_argsCount; i ++)
    {
        _args[i] = new char[strlen(other.getArg(i)) + 1];
        strcpy(this->_args[i], other.getArg(i));
    }
}

void Args::addArg(const char *arg)
{
    char **temp = new char* [_argsCount + 1];

    for(int i = 0; i < _argsCount; i ++)
        temp[i] = _args[i];

    temp[_argsCount] = new char[strlen(arg) + 1];
    strcpy(temp[_argsCount], arg);

    _argsCount ++;

    delete [] _args;
    _args = temp;
}

const char* Args::getArg(int i) const
{
    if (i >= 0 && i < _argsCount)
       return _args[i];
    return nullptr;
}

int Args::getCount() const
{
    return _argsCount;
}
