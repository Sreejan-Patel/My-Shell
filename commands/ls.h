#ifndef MY_SHELL_LS_H
#define MY_SHELL_LS_H

#include "../globals.h"
#include "../utils/util.h"
#include "../utils/inputmat.h"

void command_ls(token_mat arg);
void ls(char* path,int flag_a);
void ls_l(char* path,int flag_a);


long long int get_block_size(char* directory,int flag_a);
void dir_arg(char* arg,int flag_a,int flag_l,int flag_la);


#endif //MY_SHELL_LS_H
