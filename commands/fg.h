#ifndef MY_SHELL_FG_H
#define MY_SHELL_FG_H

#include "../globals.h"
#include "../utils/inputmat.h"
#include "../utils/processmat.h"
#include "../processer/bgprocess.h"
#include "../commands/pinfo.h"

void command_fg(token_mat arg);
void add_fgprocess();

#endif //MY_SHELL_FG_H
