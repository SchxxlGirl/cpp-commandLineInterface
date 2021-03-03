#include<iostream>
#include<stdlib.h>

#include "../inc/cli.h"
#include "../inc/args.h"

void print (Args args)
{
    for (int i = 0; i < args.get_count(); i ++)
        std::cout << Cli::info << "print : " << i << " - " << args.get_arg(i) << std::endl;
}

void get_sum (Args args)
{
    int sum = 0;

    for (int i = 0; i < args.get_count(); i ++)
        sum += atoi(args.get_arg(i));

    std::cout << Cli::info << "get_sum : sum = " << sum << std::endl;
}

void print_hello (Args args)
{
    std::cout << Cli::info << "print_hellp : hello" << std::endl;
}

int main(void)
{
    Cli my_cli;

    my_cli.set_prompt("> ");

    my_cli.add_command("print", print);
    my_cli.add_command("get_sum", get_sum);
    my_cli.add_command("print_hellp", print_hello);

    while (1)
    {
        my_cli.get();
    }

    return 0;
}
