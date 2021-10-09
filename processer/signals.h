#ifndef MY_SHELL_SIGNALS_H
#define MY_SHELL_SIGNALS_H

#include "../globals.h"
#include "../processer/prompt.h"
#include "../commands/fg.h"

void initialize_signals();
void sigtstp_handler(int sig_num);
void sigint_handler(int sig_num);

#endif //MY_SHELL_SIGNALS_H
