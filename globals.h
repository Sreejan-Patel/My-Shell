#ifndef MY_SHELL_GLOBALS_H
#define MY_SHELL_GLOBALS_H

#include <stdio.h>

#define MAX_TOKEN_LENGTH 1000
#define MAX_TOKENS 50
#define MAX_PATH_LENGTH 1000

extern char *shell_path;
extern char *prev_path;
extern char *shell;
extern char *user_name;
extern char *system_name;
extern char *curr_path;

extern unsigned int shell_path_length;
extern int in_shell;
extern int is_bg;
typedef struct arg_mat token_mat;

typedef struct process process;
extern struct process **run;

#endif //MY_SHELL_GLOBALS_H
