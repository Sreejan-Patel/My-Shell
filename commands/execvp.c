#include "execvp.h"

// executes the non-builtin commands and bg processes

void command_execvp(token_mat arg){

    if(strcmp(arg.args[arg.num_args],"&") == 0) {
        is_bg = 1;
    }
    else{
        is_bg = 0;
    }
    int child = fork();
    if(child == -1){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: execvp - Could not fork\n");
        error(error1);
        free(error1);
    }
    else if(child == 0) {
        // child process
        if (is_bg) {
            setpgid(0, 0);
        }

        int i;
        char *temp[MAX_TOKENS];
        for (i = 0; i < MAX_TOKENS; i++) {
            if (arg.args[i] != NULL) {
                temp[i] = arg.args[i];
            } else
                break;
        }
        temp[i] = NULL;

        if (is_bg) {
            temp[i-1] = NULL;
            if (execvp(temp[0], temp) < 0){     //If the command does not exist
                char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                sprintf(error1,"Error: execvp - No File or Command or Directory\n");
                error(error1);
                free(error1);
                exit(1);
            }
        }
        else {
            if (execvp(temp[0], temp) < 0) { //If the command does not exist
                char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                sprintf(error1,"Error: execvp - No File or Command or Directory\n");
                error(error1);
                free(error1);
                exit(1);
            }
        }
        exit(0);

    }
    else {
        int i;
        if (!is_bg){
            fg_run[0]->pid = child;
            strcpy(fg_run[0]->name,arg.args[0]);
            for(int j = 1 ; j <= arg.num_args; j++){
                strcat(fg_run[0]->name," ");
                strcat(fg_run[0]->name,arg.args[j]);
            }

            waitpid(child, &i, WUNTRACED); //if it is not a background process, wait, till it gets over
        }
        else {
            add_process(arg,child);
            printf(ANSI_GREEN_BOLD"%d\n"ANSI_DEFAULT,child);
        }
    }
}