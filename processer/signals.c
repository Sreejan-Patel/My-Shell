#include "signals.h"

void initialize_signals(){
    signal(SIGTSTP, sigtstp_handler);
    signal(SIGINT, sigint_handler);
}

void sigtstp_handler(int sig_num){
    if(fg_run[0]->pid != -1){
        kill(fg_run[0]->pid,SIGTSTP);

        int i;
        for(i = 0 ; i < MAX_TOKENS ; i++){
            if(run[i]->name[0] == '\0'){
                strcpy(run[i]->name,fg_run[0]->name);
                run[i]->pid = fg_run[0]->pid;
                break;
            }
        }
        if(i == MAX_TOKENS){
            printf("Error- Max no of jobs reached!\n");
            return;
        }
        strcpy(fg_run[0]->name,"\0");
        fg_run[0]->pid = -1;
        return;
    }
    printf("\n");
    prompt_print();
    fflush(stdout);
}

void sigint_handler(int sig_num){
    if(fg_run[0]->pid != -1){
        kill(fg_run[0]->pid,SIGINT);
        strcpy(fg_run[0]->name,"\0");
        fg_run[0]->pid = -1;
        return;
    }
    printf("\n");
    prompt_print();
    fflush(stdout);
}


