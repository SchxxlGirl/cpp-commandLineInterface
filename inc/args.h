#ifndef ARGS_H
#define ARGS_H

class Args
{

private :


    char **_args;

    int _argsCount;


public :


    Args() : _args(nullptr), _argsCount(0) {};

    Args(const Args& other);

    virtual ~Args();

    
    void addArg(const char *arg);

    const char* getArg (int i) const;

    int getCount() const;


};

#endif
