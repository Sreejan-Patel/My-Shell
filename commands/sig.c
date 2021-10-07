#include "sig.h"

void command_sig(token_mat arg){
    if(arg.num_args != 2){
        printf("Error Wrong Arguments!\n");
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
        printf("Error No job\n");
        return;
    }
    if(signal_number < 0 || signal_number > 32){
        printf("Error Invalid Signal Number\n");
        return;
    }

    int job_pid = run[job_number-1]->pid;

    kill(job_pid,signal_number);



}