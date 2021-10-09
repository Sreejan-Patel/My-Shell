#include "bg.h"

void command_bg(token_mat arg){
    if(arg.num_args != 1){
        printf("Error Invalid Arguments!\n");
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

    if(job_number < 1 || job_number > count+1){
        printf("Error Invalid job_number!\n");
        return;
    }

    int job_pid = run[job_number-1]->pid;
    char pid[MAX_TOKENS];
    sprintf(pid,"%d",job_pid);
    char* stat = status(pid);

    if(strcmp(stat,"R") == 0 || strcmp(stat,"S") == 0){
        printf("The background process is already running!\n");
        return;
    }
    if(kill(job_pid, SIGCONT) < 0){
        perror("Error SIGCONT! ");
        return;
    }

    printf("[%d] %s [%d] stopped background process resumed in background!\n", job_number, run[job_number-1]->name, job_pid);


}