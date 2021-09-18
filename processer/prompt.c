#include "prompt.h"

void initialize(){
    shell_path = (char*)malloc(sizeof(char)*MAX_PATH_LENGTH);
    getcwd(shell_path,MAX_PATH_LENGTH);
    shell = "~";
    shell_path_length = strlen(shell_path);
    in_shell = 1;

    prev_path = (char*)malloc(sizeof(char)*MAX_PATH_LENGTH);
    getcwd(prev_path,MAX_PATH_LENGTH);

}

void prompt_print(){

    char* current_path = get_curr_path();

    if(in_shell == 1){
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
    else{
            printf("<%s@",get_user_name());
            get_system_name();
            printf("%s>",current_path);

    }




}