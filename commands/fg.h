#ifndef MY_SHELL_FG_H
#define MY_SHELL_FG_H

#include "../utils/files.h"
#include "../utils/inputmat.h"
#include "../processer/prompt.h"
#include "../processer/bgprocess.h"
#include "../processer/tokenizer.h"
#include "../globals.h"
#include "../commands/pinfo.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

void command_fg(token_mat arg);


#endif //MY_SHELL_FG_H
