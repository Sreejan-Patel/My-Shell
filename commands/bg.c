#include "bg.h"

// resumes a stopped bgprocess
void command_bg(token_mat arg){
    if(arg.num_args != 1){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: bg - Wrong Arguments\n");
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

    if(job_number < 1 || job_number > count+1){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: bg - Invalid Job Number\n");
        error(error1);
        free(error1);
        return;
    }

    int job_pid = run[job_number-1]->pid;
    char pid[MAX_TOKENS];
    sprintf(pid,"%d",job_pid);
    char* stat = status(pid);
    if(stat == NULL)
        return;
    if(strcmp(stat,"R") == 0 || strcmp(stat,"S") == 0){         // do nothing if already running
        printf(ANSI_GREEN_BOLD"The Background process is already Running\n"ANSI_DEFAULT);
        return;
    }
    if(kill(job_pid, SIGCONT) < 0){     // continues the stopped bgprocess
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: bg - kill:SIGCONT\n");
        error(error1);
        free(error1);
        return;
    }

    char *success1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
    sprintf(success1,"[%d] %s [%d] Stopped Background process resumed in Background\n", job_number, run[job_number-1]->name, job_pid);
    success(success1);
    free(success1);

}