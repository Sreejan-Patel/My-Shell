#ifndef MY_SHELL_TOKENIZER_H
#define MY_SHELL_TOKENIZER_H

#include "../utils/files.h"
#include "../globals.h"
#include <stdlib.h>
#include "../utils/inputmat.h"
#include "../commands/echo.h"
#include "../commands/pwd.h"
#include "../commands/cd.h"
#include "../commands/ls.h"
#include "bgprocess.h"
#include "../commands/execvp.h"
#include "../commands/pinfo.h"

void tokenize_input(char *input);
void tokenize(token_mat args_mat);
void execute(token_mat arg,long int repeat);

void redirections(token_mat arg,long int repeat);

#endif //MY_SHELL_TOKENIZER_H
