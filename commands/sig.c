#include "sig.h"

// sends a signal to specified job using kill
void command_sig(token_mat arg){
    if(arg.num_args != 2){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: sig - Wrong Arguments\n");
        error(error1);
        free(error1);
        return;
    }


    int count = -1;
    for(int i = 0 ; i < MAX_TOKENS ; i++){
        if(run[i]->name[0] == '\0')
            break;
        else
            count++;
    }

    int job_number = atoi(arg.args[1]);
    int signal_number = atoi(arg.args[2]);

    if(job_number < 1 || job_number > count+1){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Invalid Job Number\n");
        error(error1);
        free(error1);
        return;
    }
    if(signal_number < 0 || signal_number > 32){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Invalid Signal Number\n");
        error(error1);
        free(error1);
        return;
    }

    int job_pid = run[job_number-1]->pid;

    if(kill(job_pid,signal_number) < 0){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Could not send Signal\n");
        error(error1);
        free(error1);
        return;
    }

}