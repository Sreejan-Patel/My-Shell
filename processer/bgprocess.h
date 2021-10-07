
#ifndef MY_SHELL_BGPROCESS_H
#define MY_SHELL_BGPROCESS_H

#include "tokenizer.h"
#include "../utils/files.h"
#include "../utils/inputmat.h"
#include <unistd.h>
#include "../globals.h"
#include <stdlib.h>

void print_finished_bgprocess();
void delete_process(int job_number);

#endif //MY_SHELL_BGPROCESS_H
