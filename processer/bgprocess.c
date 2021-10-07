#include "bgprocess.h"
/*
    -print_finished_bgprocess() prints the info of finished bgprocess
*/
void print_finished_bgprocess(){
    int pid, status;

    while(!0){

        pid = waitpid(-1, &status, WNOHANG | WUNTRACED); //WNOHANG is for killed children; WUNTRACED is for stopped children
        if (pid <= 0){
            return;
        }

        for(int i = 0; i < MAX_TOKENS ; i++){
            if(run[i]->pid == pid){
                if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
                    printf("%s with pid %d exited normally with status %d\n", run[i]->name, run[i]->pid, WEXITSTATUS(status));
                    delete_process(i);
                }
                else{
                    printf("%s with pid %d exited abnormally with error status %d\n", run[i]->name, run[i]->pid, WEXITSTATUS(status));
                    delete_process(i);
                }
            }
            else
                continue;

        }
    }
}

void delete_process(int job_number){
    for(int j = job_number; j < MAX_TOKENS-1 ; j++){
        strcpy(run[j]->name,run[j+1]->name);
        run[j]->pid = run[j+1]->pid;
    }
    strcpy(run[MAX_TOKENS-1]->name,"\0");
    run[MAX_TOKENS-1]->pid = 0;
}


