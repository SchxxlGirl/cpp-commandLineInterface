#include<iostream>

#include "../inc/cli.h"
#include "../inc/args.h"

void print (Args args)
{
    for (int i = 0; i < args.getCount(); i ++)
        std::cout << Cli::info << "print : " << i << " - " << args.getArg(i) << std::endl;
}

void getSum (Args args)
{
    int sum = 0;

    for (int i = 0; i < args.getCount(); i ++)
        sum += atoi(args.getArg(i));

    std::cout << Cli::info << "getSum : sum = " << sum << std::endl;
}

void printHello (Args args)
{
    std::cout << Cli::info << "printHello : hello" << std::endl;
}

int main(void)
{
    Cli myCli;

    myCli.setPrompt("> ");

    myCli.addCommand("print", print);
    myCli.addCommand("getSum", getSum);
    myCli.addCommand("printHello", printHello);

    while (1)
    {
        myCli.get();
    }

    return 0;
}
