#ifndef MY_SHELL_EXECVP_H
#define MY_SHELL_EXECVP_H

#include "../utils/files.h"
#include "../utils/inputmat.h"
#include "../globals.h"
#include "../processer/tokenizer.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void command_execvp(token_mat arg);
void add_process(token_mat arg,int child);


#endif //MY_SHELL_EXECVP_H
