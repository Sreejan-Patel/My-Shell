#ifndef MY_SHELL_PINFO_H
#define MY_SHELL_PINFO_H

#include "../globals.h"
#include "../utils/util.h"
#include "../utils/inputmat.h"

void command_pinfo(token_mat arg);
char *status(char* pid);
char* memory(char* pid);
char* exe(char* pid);


#endif //MY_SHELL_PINFO_H
