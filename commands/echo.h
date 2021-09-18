#ifndef MY_SHELL_ECHO_H
#define MY_SHELL_ECHO_H

#include "../utils/files.h"
#include "../utils/inputmat.h"
#include "../processer/prompt.h"
#include "../processer/tokenizer.h"
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void command_echo(token_mat arg);


#endif //MY_SHELL_ECHO_H
