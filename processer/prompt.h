#ifndef MY_SHELL_PROMPT_H
#define MY_SHELL_PROMPT_H

#include <stdio.h>
#include "../globals.h"
#include "../utils/files.h"
#include "../utils/bgprocessmat.h"
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>

void initialize();
void prompt_print();

#endif //MY_SHELL_PROMPT_H
