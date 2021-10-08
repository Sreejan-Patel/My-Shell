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

}

// prints the prompt as specified and if there is any bgprocess running a smiley face lets you know

void prompt_print(){

    char* current_path = get_curr_path();

    if(is_bg){
        if(in_shell){
            if(strcmp(shell_path,current_path) == 0){
                printf(":')<%s@",get_user_name());
                get_system_name();
                printf("%s>",shell);
            }
            else{
                printf(":')<%s@",get_user_name());
                get_system_name();
                printf("%s",shell);
                printf("%s>",get_relative_path(current_path));
            }
        }
        else{                                       //outside the shell directory
            printf("<%s@",get_user_name());
            get_system_name();
            printf("%s>",current_path);

        }
    }
    else{
        if(in_shell){
            if(strcmp(shell_path,current_path) == 0){
                printf("<%s@",get_user_name());
                get_system_name();
                printf("%s>",shell);
            }
            else{
                printf("<%s@",get_user_name());
                get_system_name();
                printf("%s",shell);
                printf("%s>",get_relative_path(current_path));
            }
        }
        else{                                       //outside the shell directory
            printf("<%s@",get_user_name());
            get_system_name();
            printf("%s>",current_path);

        }
    }




}