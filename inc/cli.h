#ifndef CLI_H
#define CLI_H

#include "args.h"

class Cli 
{

private :


    char *_prompt;

    char **_commands;

    void (**_func)(Args);

    int _commandsCount;


public :


    static const char *erro;

    static const char *warn;

    static const char *info;


public :


    Cli() : _prompt(nullptr), _commands(nullptr), _func(nullptr), _commandsCount(0) {};

    virtual ~Cli();


    int setPrompt(const char *prompt);

    const char* getPrompt() const;

    int addCommand(const char *command, void (*func) (Args));

    int get() const;
  

};

#endif
