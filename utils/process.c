#include "process.h"

// adds incoming bgprocess to run/jobs
void add_process(token_mat arg,int child){
    int j;
    for(j = 0 ; j < MAX_TOKENS ; j++){
        if(run[j]->name[0] == '\0'){
            strcpy(run[j]->name,arg.args[0]);
            for(int k = 1 ; k < arg.num_args; k++){
                strcat(run[j]->name," ");
                strcat(run[j]->name,arg.args[k]);
            }
            run[j]->pid = child;
            break;
        }
        else
            continue;
    }
    if(j == MAX_TOKENS){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Max Jobs Reached - Job not added\n");
        error(error1);
        free(error1);
        return;
    }
}

// deletes the job after completion/termination
void delete_process(int job_number){
    for(int j = job_number; j < MAX_TOKENS-1 ; j++){
        strcpy(run[j]->name,run[j+1]->name);
        run[j]->pid = run[j+1]->pid;
    }
    strcpy(run[MAX_TOKENS-1]->name,"\0");
    run[MAX_TOKENS-1]->pid = 0;
}

// adds a fgprocess to bgprocesses(run)/jobs when ctrl-z occurs
void add_fgprocess(){
    int i;
    for(i = 0 ; i < MAX_TOKENS ; i++){
        if(run[i]->pid == fg_run[0]->pid)
            return;
        if(run[i]->name[0] == '\0'){
            strcpy(run[i]->name,fg_run[0]->name);
            run[i]->pid = fg_run[0]->pid;
            break;
        }
    }
    if(i == MAX_TOKENS){
        char *error1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
        sprintf(error1,"Error: Max Jobs Reached - Job not added\n");
        error(error1);
        free(error1);
        return;
    }
    strcpy(fg_run[0]->name,"\0");
    fg_run[0]->pid = -1;
}