#ifndef CLI_H
#define CLI_H

#include "args.h"

class Cli 
{

private :


    char *_prompt;

    char **_commands;

    void (**_func)(Args);

    int _commands_count;


public :


    static const char *erro;

    static const char *warn;

    static const char *info;


public :


    Cli() : _prompt(nullptr), _commands(nullptr), _func(nullptr), _commands_count(0) {};

    virtual ~Cli();


    int set_prompt(const char *prompt);

    const char* get_prompt() const;

    int add_command(const char *command, void (*func) (Args));

    int get() const;
  

};

#endif
