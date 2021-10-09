#ifndef MY_SHELL_PROCESSMAT_H
#define MY_SHELL_PROCESSMAT_H

#include "../globals.h"

struct process
{
    char name[MAX_NAME_LENGTH];
    int pid;
};

void make_bgprocess_mat();
void make_fgprocess_mat();



#endif //MY_SHELL_PROCESSMAT_H
