#ifndef MY_SHELL_GLOBALS_H
#define MY_SHELL_GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/utsname.h>
#include <string.h>
#include <signal.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_TOKEN_LENGTH 1024
#define MAX_TOKENS 69
#define MAX_PATH_LENGTH 1024
#define MAX_NAME_LENGTH 1024

extern char *shell_path;
extern char *prev_path;
extern char *shell;
extern char *user_name;
extern char *system_name;
extern char *curr_path;

extern unsigned int shell_path_length;
extern int in_shell;
extern int shell_pid;
extern int is_bg;
typedef struct arg_mat token_mat;

typedef struct process process;
extern struct process **run;
extern struct process **fg_run;

#endif //MY_SHELL_GLOBALS_H
