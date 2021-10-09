#ifndef MY_SHELL_PROCESS_H
#define MY_SHELL_PROCESS_H

#include "../globals.h"
#include "inputmat.h"
#include "processmat.h"

void add_process(token_mat arg,int child);
void delete_process(int job_number);
void add_fgprocess();

#endif //MY_SHELL_PROCESS_H
