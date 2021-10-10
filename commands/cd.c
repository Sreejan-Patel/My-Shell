#include "cd.h"

// executes the cd command as specified
void command_cd(token_mat arg){

    // cd can have only 1 argument
    if(arg.num_args > 1){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: cd - Too many Arguments\n");
        error(error1);
        free(error1);
        return;
    }

    // cd has no argument
    if (arg.num_args == 0) {
        prev_path = get_curr_path();
        chdir(shell_path);
        return;
    }




    unsigned int path_length = strlen(arg.args[1]);

    // prev_path function
    if(path_length == 1 && arg.args[1][0] == '-'){

        // if the prev_path is not the shell_path
        if(strcmp(shell_path,prev_path) != 0) {
            char *relative_path = get_relative_path(prev_path);
            char *temp = prev_path;
            prev_path = get_curr_path();
            chdir(temp);

            if(strncmp(shell_path,temp,shell_path_length) == 0)
                in_shell = 1;
            else
                in_shell = 0;
            printf(ANSI_GREEN_BOLD"%s\n"ANSI_DEFAULT, relative_path);
            return;
        }
        // if the prev_path is the shell_path
        else{
            prev_path = get_curr_path();
            chdir(shell_path);
            in_shell = 1;
            printf(ANSI_GREEN_BOLD"%s\n"ANSI_DEFAULT,shell);
            return;
        }
    }

    prev_path = get_curr_path();


    if (path_length == 1 && arg.args[1][0] == '~')
        chdir(shell_path);
    else if (arg.args[1][0] == '~' && arg.args[1][1] == '/') {
        chdir(shell_path);
        if (chdir(arg.args[1] + 2) < 0) {
            char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
            sprintf(error1,"Error: cd - No such File or Directory\n");
            error(error1);
            free(error1);
            chdir(prev_path);
            return;
        }

    }
    else if (arg.args[1][0] != '-') {
        if (chdir(arg.args[1]) < 0) {
            char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
            sprintf(error1,"Error: cd - No such File or Directory\n");
            error(error1);
            free(error1);
            return;
        }
    }

    // To check if we are inside the My_Shell directory
    char* temp = get_curr_path();
    if(strncmp(shell_path,temp,shell_path_length) == 0)
        in_shell = 1;
    else
        in_shell = 0;


}

