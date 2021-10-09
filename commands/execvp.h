#ifndef MY_SHELL_EXECVP_H
#define MY_SHELL_EXECVP_H

#include "../globals.h"
#include "../utils/inputmat.h"
#include "../utils/processmat.h"

void command_execvp(token_mat arg);
void add_process(token_mat arg,int child);


#endif //MY_SHELL_EXECVP_H
