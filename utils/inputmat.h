#ifndef MY_SHELL_INPUTMAT_H
#define MY_SHELL_INPUTMAT_H

#include "../globals.h"
#include "../processer/prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../processer/tokenizer.h"


struct arg_mat {
    char **args;
    int num_args;
};

token_mat make_args_mat();

#endif //MY_SHELL_INPUTMAT_H
