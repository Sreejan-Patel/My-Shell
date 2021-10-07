#ifndef MY_SHELL_SIG_H
#define MY_SHELL_SIG_H

#include "../utils/files.h"
#include "../utils/inputmat.h"
#include "../processer/prompt.h"
#include "../processer/tokenizer.h"
#include "../globals.h"
#include "../commands/pinfo.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>

void command_sig(token_mat arg);

#endif //MY_SHELL_SIG_H
