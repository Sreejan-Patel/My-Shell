
#ifndef MY_SHELL_BGPROCESS_H
#define MY_SHELL_BGPROCESS_H

#include "tokenizer.h"
#include "../utils/files.h"
#include "../utils/inputmat.h"
#include <unistd.h>
#include "../globals.h"
#include <stdlib.h>

void display_killed_children();
void print_proc_details(process *proc, int status);
void print_n(char *s);
void print(char *s);

#endif //MY_SHELL_BGPROCESS_H
