#ifndef MY_SHELL_LS_H
#define MY_SHELL_LS_H

#include "../utils/files.h"
#include "../utils/inputmat.h"
#include "../processer/prompt.h"
#include "../processer/tokenizer.h"
#include "../globals.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <grp.h>
#include <time.h>
#include <math.h>

void command_ls(token_mat arg);
void ls(char* path,int flag_a);
void ls_l(char* path,int flag_a);


long long int get_block_size(char* directory,int flag_a);
void dir_arg(char* arg,int flag_a,int flag_l,int flag_la);


#endif //MY_SHELL_LS_H
