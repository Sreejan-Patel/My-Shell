#ifndef MY_SHELL_SIGNALS_H
#define MY_SHELL_SIGNALS_H

#include <stdio.h>
#include "../globals.h"
#include "../utils/files.h"
#include "../utils/processmat.h"
#include "../processer/prompt.h"
#include "../commands/fg.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void initialize_signals();
void sigtstp_handler(int sig_num);
void sigint_handler(int sig_num);

#endif //MY_SHELL_SIGNALS_H
