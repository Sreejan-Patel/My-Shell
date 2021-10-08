#ifndef MY_SHELL_PROCESSMAT_H
#define MY_SHELL_PROCESSMAT_H

#include "../globals.h"
#include "inputmat.h"
#include "files.h"
#include "../processer/prompt.h"
#include "../processer/tokenizer.h"
#include "../processer/bgprocess.h"
#include "../commands/execvp.h"

struct process
{
    char name[MAX_TOKEN_LENGTH];
    int pid;
};

void make_bgprocess_mat();
void make_fgprocess_mat();



#endif //MY_SHELL_PROCESSMAT_H
