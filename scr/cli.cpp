#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring> 

#include "../inc/cli.h"

const char *Cli::erro = "[ERRO] ";
const char *Cli::warn = "[WARN] ";
const char *Cli::info = "[INFO] ";

typedef void (*FuncPtr)(Args);

Cli::~Cli()
{
    for (int i = 0; i < _commandsCount; i ++)
        delete [] _commands[i];
    if (_commands != nullptr)
        delete [] _commands;
    if (_prompt != nullptr)
        delete [] _prompt;
    if (_func != nullptr)
        delete [] _func;
}

int Cli::setPrompt(const char *prompt)
{
    if (_prompt != nullptr)
        delete [] _prompt;

    _prompt = new char[strlen(prompt) + 1];
    strcpy(_prompt, prompt);

    return 0;
}

const char* Cli::getPrompt() const
{
    return _prompt;
}

int Cli::addCommand(const char *command, void (*func)(Args))
{
    char **temp_command = new char* [_commandsCount + 1];
    void (**temp_func)(Args) = new FuncPtr[_commandsCount + 1];

    for (int i = 0; i < _commandsCount; i ++)
    {
        temp_command[i] = _commands[i];
        temp_func[i] = _func[i];
    }

    temp_command[_commandsCount] = new char[strlen(command) + 1];
    strcpy(temp_command[_commandsCount], command);
    temp_func[_commandsCount] = func;

    _commandsCount ++;

    delete [] _commands;
    delete [] _func;

    _commands = temp_command;
    _func = temp_func;
    
    return 0;
}

int Cli::get() const
{
    printf("%s", _prompt);


    char *input = new char[128];
    char *forFree = input;
    fgets(input, 128, stdin);
    rewind(stdin);

    while (input[0] == ' ')
    {
        input = input + 1;
    }

    char command[128];
    for (int i = 0; i < 128; i ++)      // get command -<
    {
        if (input[i] == '\n' || input[i] == ' ')
        {
            input[i] = '\0';
            strcpy(command, input);
            input = &input[i + 1];
            break;
        }
    }                                   // get command >-


    Args args;                          // get args -<
    for (int i = 0; i < 128; i ++)
    {
        if (input[i] == '\n')
        {
            input[i] = '\0';
            args.addArg(input);
            input = &input[i + 1];
            i = 0;
            break;
        }
        if (input[i] == ' ')
        {
            input[i] = '\0';
            args.addArg(input);
            input = &input[i + 1];
            i = 0;
            while (input[0] == ' ')
            {
                input = input + 1;
            }
        }
        if (input[i] == '\0')
            break;
    }                                   // get args >-


    bool is_found = false;
    for (int i = 0; i < _commandsCount; i ++)
    {
        if (strcmp(command, _commands[i]) == 0)
        {
            _func[i](args);
            is_found = true;
            break;
        }
    }

    if (is_found == false && command[0] != '\0')
        std::cout << erro << command << " : command not found.\n";

    
    delete [] forFree;

    return 0;
}
