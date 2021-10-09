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
                    char *alert1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                    sprintf(alert1,"\tAlert: %s with pid %d exited normally with status %d\n",run[i]->name, run[i]->pid, WEXITSTATUS(status));
                    alert(alert1);
                    free(alert1);
                    delete_process(i);
                }
                else{
                    char *alert1 = malloc(sizeof(char)*MAX_NAME_LENGTH);
                    sprintf(alert1,"\tAlert: %s with pid %d exited abnormally with status %d\n",run[i]->name, run[i]->pid, WEXITSTATUS(status));
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
