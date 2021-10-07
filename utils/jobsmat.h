#ifndef MY_SHELL_JOBSMAT_H
#define MY_SHELL_JOBSMAT_H

#include "../globals.h"
#include "inputmat.h"
#include "files.h"
#include "../processer/prompt.h"
#include "../processer/tokenizer.h"
#include "../processer/bgprocess.h"
#include "../commands/execvp.h"


struct jobs_list
{
    char name[MAX_TOKEN_LENGTH];
    int pid;
};

void make_jobs_mat();

#endif //MY_SHELL_JOBSMAT_H
