#ifndef MY_SHELL_PROMPT_H
#define MY_SHELL_PROMPT_H

#include "../globals.h"
#include "../utils/util.h"
#include "../utils/processmat.h"
#include "../utils/print.h"
#include "signals.h"
#include "bgprocess.h"

void initialize();
void prompt_print();

#endif //MY_SHELL_PROMPT_H
