#ifndef MY_SHELL_FILES_H
#define MY_SHELL_FILES_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../globals.h"
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <math.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/utsname.h>


void clear_screen();
char* get_user_name();
void get_system_name();
char* get_curr_path();
char* get_relative_path(char* current_path);



#endif //MY_SHELL_FILES_H
