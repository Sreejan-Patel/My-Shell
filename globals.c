#include "globals.h"

char *shell_path;
char *shell;
char *user_name;
char *system_name;
char *curr_path;
char *prev_path;

int in_shell;
unsigned int shell_path_length;
int is_bg;
int shell_pid;

struct process **run;
struct process **fg_run;

struct termios terminal;