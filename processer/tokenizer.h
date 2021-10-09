#ifndef MY_SHELL_TOKENIZER_H
#define MY_SHELL_TOKENIZER_H

#include "../globals.h"

#include "../utils/inputmat.h"
#include "../utils/util.h"

#include "../commands/echo.h"
#include "../commands/pwd.h"
#include "../commands/cd.h"
#include "../commands/ls.h"
#include "../commands/jobs.h"
#include "../commands/sig.h"
#include "../commands/fg.h"
#include "../commands/bg.h"
#include "../commands/execvp.h"
#include "../commands/pinfo.h"

#include "redirections.h"
#include "pipeline.h"
#include "bgprocess.h"

void tokenize_input(char *input);
void tokenize(token_mat args_mat);
void execute(token_mat arg,long int repeat);

#endif //MY_SHELL_TOKENIZER_H
