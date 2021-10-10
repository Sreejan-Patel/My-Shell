#include "bgprocess.h"

// prints the info of jobs signaled by SIGCHLD
void print_finished_bgprocess(){
    int pid, status;

    while(!0){

        pid = waitpid(-1, &status, WNOHANG); //WNOHANG is for killed children
        if (pid <= 0){
            return;
        }

        for(int i = 0; i < MAX_TOKENS ; i++){
            if(run[i]->pid == pid){
                // exits after completion of the bg process
                if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS) {
                    char *alert1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                    sprintf(alert1,"\t\nAlert: %s with pid %d exited normally with status %d\n",run[i]->name, run[i]->pid, WEXITSTATUS(status));
                    alert(alert1);
                    free(alert1);
                    delete_process(i);
                }
                else if(WIFSTOPPED(status))     // ctrl-z
                    continue;
                else{                           // signaled/forcefully terminated
                    char *alert1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                    sprintf(alert1,"\t\nAlert: %s with pid %d exited abnormally with error code %d\n",run[i]->name, run[i]->pid, WIFSIGNALED(status));
                    alert(alert1);
                    free(alert1);
                    delete_process(i);
                }
            }
            else
                continue;

        }
    }
}
