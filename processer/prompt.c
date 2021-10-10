#include "prompt.h"

// initializes the shell_path , prev_path , shell , in_shell and bgprocessmat

void initialize(){
    shell_path = (char*)malloc(sizeof(char)*MAX_PATH_LENGTH);
    getcwd(shell_path,MAX_PATH_LENGTH);
    shell = "~";
    shell_path_length = strlen(shell_path);
    in_shell = 1;

    prev_path = (char*)malloc(sizeof(char)*MAX_PATH_LENGTH);
    getcwd(prev_path,MAX_PATH_LENGTH);

    shell_pid = getpid();

    make_bgprocess_mat();
    make_fgprocess_mat();

    initialize_signals();
    signal(SIGCHLD,print_finished_bgprocess);
}

// prints the prompt as specified and if there is any bgprocess running a smiley face lets you know

void prompt_print(){

    char* current_path = get_curr_path();
    char* prompt1 = malloc(sizeof(char)*MAX_NAME_LENGTH);

    if(in_shell){
        if(strcmp(shell_path,current_path) == 0){
            sprintf(prompt1,"<%s@%s:%s>",get_user_name(),get_system_name(),shell);
            prompt(prompt1);
        }
        else{
            sprintf(prompt1,"<%s@%s:%s%s>",get_user_name(),get_system_name(),shell, get_relative_path(current_path));
            prompt(prompt1);
        }
    }
    else{                                       //outside the shell directory
        sprintf(prompt1,"<%s@%s:%s>",get_user_name(),get_system_name(),current_path);
        prompt(prompt1);
    }
    free(prompt1);
}