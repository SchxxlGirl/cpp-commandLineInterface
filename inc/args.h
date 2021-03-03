#ifndef ARGS_H
#define ARGS_H

class Args
{

private :


    char **_args;

    int _args_count;


public :


    Args() : _args(nullptr), _args_count(0) {};

    Args(const Args& other);

    ~Args();

    
    void add_arg(const char *arg);

    const char* get_arg (int i) const;

    int get_count() const;


};

#endif
