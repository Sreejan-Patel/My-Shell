#ifndef MY_SHELL_PINFO_H
#define MY_SHELL_PINFO_H

#include "../globals.h"
#include "../processer/tokenizer.h"
#include "../utils/files.h"
#include "../utils/inputmat.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <libproc.h>
#include <sys/proc_info.h>

void command_pinfo(token_mat arg);


#endif //MY_SHELL_PINFO_H
