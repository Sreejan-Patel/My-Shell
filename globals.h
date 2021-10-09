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

#define ANSI_RED_BOLD "\033[1;31m"
#define ANSI_GREEN_BOLD "\033[1;32m"
#define ANSI_YELLOW_BOLD "\033[1;33m"
#define ANSI_BLUE_BOLD "\033[1;34m"
#define ANSI_PURPLE_BOLD "\033[1;35m"
#define ANSI_CYAN_BOLD "\033[1;36m"
#define ANSI_DEFAULT "\033[0m"

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
