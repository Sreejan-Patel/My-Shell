#ifndef MY_SHELL_PIPELINE_H
#define MY_SHELL_PIPELINE_H

#include "tokenizer.h"
#include "redirections.h"
#include "../globals.h"
#include "../utils/inputmat.h"
#include "../utils/files.h"
#include <stdlib.h>
#include <unistd.h>

void pipeline(token_mat arg,long int repeat);


#endif //MY_SHELL_PIPELINE_H
