#include "signals.h"

void initialize_signals(){
    signal(SIGTSTP, sigtstp_handler);
    signal(SIGINT, sigint_handler);
}

void sigtstp_handler(int sig_num){
    if(fg_run[0]->pid != -1){
        kill(fg_run[0]->pid,SIGTSTP);
        add_fgprocess();
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


