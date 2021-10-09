#include "util.h"

/*
consists of the following -
    -clearscreen : clears the terminal screen
    -get_user_name : gets the username operating the system
    -get_system_name : gets the systemname
    -get_curr_path() : gets the current path
    -get_relative_path() : gets the relative path w.r.t shell path
*/


void clear_screen(){
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, strlen(CLEAR_SCREEN_ANSI));
}

char* get_user_name(){
    user_name = malloc(sizeof(char)*MAX_NAME_LENGTH);
    struct passwd *user = getpwuid(getuid());
    strcpy(user_name,user->pw_name);

    return user_name;
}

void get_system_name(){

    int flag;
    system_name = malloc(sizeof(char)*MAX_NAME_LENGTH);
    flag = gethostname(system_name,MAX_NAME_LENGTH);
    if(flag < 0){
        perror("System Name!");
    }

    printf("%s:",system_name);
    /*
    int flag;
    struct utsname unameData;
    flag = uname(&unameData);
    if(flag < 0){
        perror("System Name!");
        exit(1);
    }
    system_name = malloc(sizeof(char)*MAX_TOKEN_LENGTH);
    system_name = unameData.sysname;
    printf("%s:",unameData.sysname);
     */

}


char* get_curr_path(){
    curr_path = malloc(sizeof(char)*MAX_PATH_LENGTH);
    getcwd(curr_path,MAX_PATH_LENGTH);

    return curr_path;
}

char* get_relative_path(char* current_path){
    char* relative_path;
    relative_path = malloc(sizeof(char)*MAX_PATH_LENGTH);

    int match = 0;
    int flag = 0;
    unsigned int current_path_length = strlen(current_path);
    for (int i = 0; i < shell_path_length && i < current_path_length; i++) {
        if (shell_path[i] != current_path[i]){
            match = i;
            flag = 1;
            break;
        }
    }
    if (!flag){
        match = (int) fmin(shell_path_length, current_path_length);
    }

    if (match >= shell_path_length){
        sprintf(relative_path,"%s",current_path + match);
    }


    return relative_path;
}